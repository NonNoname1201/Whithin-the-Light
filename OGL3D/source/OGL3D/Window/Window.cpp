//
// Created by User on 21.07.2024.
//

#include <OGL3D/Window/Window.h>
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
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwError, 0, errorMessage, 256, NULL);
        MessageBox(NULL, errorMessage, "Error", MB_OK);
    }

    assert(m_WindowHandle);

    SetWindowLongPtr((HWND) m_WindowHandle, GWLP_USERDATA, (LONG_PTR) this);

    ShowWindow((HWND) m_WindowHandle, SW_SHOW);
    UpdateWindow((HWND) m_WindowHandle);
}

Window::~Window() {
    DestroyWindow((HWND) m_WindowHandle);

}
