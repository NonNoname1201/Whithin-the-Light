//
// Created by User on 22.07.2024.
//

#include "OGL3D/Game/Game.h"
#include "OGL3D/GraphicsEngine/GraphicsEngine.h"
#include <Windows.h>

void Game::run() {
    onCreate();
    while (m_isRunning) {
        MSG msg = {};
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                m_isRunning = false;
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        Sleep(1);
        onUpdate();
    }
    onQuit();
}