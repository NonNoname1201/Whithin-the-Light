//
// Created by User on 21.07.2024.
//

#include <OGL3D/Window/Window.h>
#include <glad/glad.h>
#include <glad/glad_wgl.h>
#include <Windows.h>
#include <cassert>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_DESTROY: {
            Window *window = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
            break;
        }
        case WM_CLOSE: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

Window::Window() {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpszClassName = "OGL3DWindow";
    wc.lpfnWndProc = WindowProc;

    auto classId = RegisterClassEx(&wc);
    assert(classId);

    RECT rc = {0, 0, 1024, 768};
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU, false);

    m_WindowHandle = CreateWindowEx(0, (LPCTSTR)classId, "Within the Light",
                                    WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT,
                                    CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top,
                                    nullptr, nullptr, nullptr, nullptr);


    if (!m_WindowHandle) {
        DWORD errorCode = GetLastError();
        DWORD dwError = GetLastError();
        char errorMessage[256];
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, dwError, 0, errorMessage, 256, NULL);
        MessageBox(nullptr, errorMessage, "Error", MB_OK);
    }

    assert(m_WindowHandle);

    SetWindowLongPtr((HWND) m_WindowHandle, GWLP_USERDATA, (LONG_PTR) this);

    ShowWindow((HWND) m_WindowHandle, SW_SHOW);
    UpdateWindow((HWND) m_WindowHandle);


    auto windowDC = GetDC((HWND) m_WindowHandle);
    int pixelFormatAttribs[] = {
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
            WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
            WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
            WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
            WGL_COLOR_BITS_ARB, 32,
            WGL_ALPHA_BITS_ARB, 8,
            WGL_DEPTH_BITS_ARB, 24,
            WGL_STENCIL_BITS_ARB, 8,
            0
    };
    int pixelFormat = 0;
    UINT numFormats = 0;
    wglChoosePixelFormatARB (windowDC, pixelFormatAttribs, nullptr, 1, &pixelFormat, &numFormats);
    assert(numFormats);

    PIXELFORMATDESCRIPTOR pfd = {};
    DescribePixelFormat(windowDC, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
    SetPixelFormat(windowDC, pixelFormat, &pfd);

    int contextAttribs[] = {
            WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
            WGL_CONTEXT_MINOR_VERSION_ARB, 6,
            WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            0
    };

    m_WindowDC = wglCreateContextAttribsARB(windowDC, 0, contextAttribs);
    assert(m_WindowDC);
}

Window::~Window() {
    wglDeleteContext(HGLRC(m_WindowDC));
    DestroyWindow((HWND) m_WindowHandle);

}

void Window::makeCurrentContext() {
    wglMakeCurrent(GetDC(HWND(m_WindowHandle)), HGLRC(m_WindowDC));
}

void Window::present(bool vSync) {
    wglSwapIntervalEXT(vSync);
    wglSwapLayerBuffers(GetDC(HWND(m_WindowHandle)), WGL_SWAP_MAIN_PLANE);
}
