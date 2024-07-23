//
// Created by User on 22.07.2024.
//

#include "OGL3D/Graphics/GraphicsEngine.h"
#include "glad/glad.h"
#include "glad/glad_wgl.h"
#include <cassert>
#include <stdexcept>

GraphicsEngine::GraphicsEngine() {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpszClassName = "OGL3DDummyWindow";
    wc.lpfnWndProc = DefWindowProc;
    wc.style = CS_OWNDC;

    auto classId = RegisterClassEx(&wc);
    assert(classId);

    auto dummyWindow = CreateWindowEx(0, (LPCTSTR) classId, "Within the Light",
                                      WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT,
                                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                                      nullptr, nullptr, nullptr, nullptr);


    if (!dummyWindow) {
        DWORD errorCode = GetLastError();
        DWORD dwError = GetLastError();
        char errorMessage[256];
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwError, 0, errorMessage, 256, NULL);
        MessageBox(NULL, errorMessage, "Error", MB_OK);
    }

    assert(dummyWindow);

    auto dummyDC = GetDC((HWND) dummyWindow);
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.cColorBits = 32;
    pfd.cAlphaBits = 8;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

    auto pixelFormat = ChoosePixelFormat(dummyDC, &pfd);
    assert(pixelFormat);
    SetPixelFormat(dummyDC, pixelFormat, &pfd);

    auto dummyContext = wglCreateContext(dummyDC);
    assert(dummyContext);

    wglMakeCurrent(dummyDC, dummyContext);

    if (!gladLoadWGL(dummyDC))
        throw std::runtime_error("Failed to initialize OpenGL context, gladLoadWGL failed");

    if (!gladLoadGL())
        throw std::runtime_error("Failed to initialize OpenGL context, gladLoadGL failed");

    wglMakeCurrent(dummyDC, nullptr);
    wglDeleteContext(dummyContext);
    ReleaseDC((HWND) dummyWindow, dummyDC);
    DestroyWindow((HWND) dummyWindow);
}

GraphicsEngine::~GraphicsEngine() = default;