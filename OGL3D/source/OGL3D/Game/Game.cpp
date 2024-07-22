//
// Created by User on 21.07.2024.
//

#include <OGL3D/Game/Game.h>
#include <OGL3D/Window/Window.h>
#include <Windows.h>

#include <memory>

Game::Game() {
    m_Window = std::make_unique<Window>();
}

Game::~Game() = default;

void Game::run() {
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
    }
}

void Game::quit() {
    m_isRunning = false;
}
