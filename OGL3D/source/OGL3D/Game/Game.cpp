//
// Created by User on 21.07.2024.
//

#include <OGL3D/Game/Game.h>
#include <OGL3D/Window/Window.h>
#include <Windows.h>

Game::Game() {
    m_Window = std::unique_ptr<Window>(new Window());
}

Game::~Game() {}

void Game::run() {
    MSG msg = {};
    while (m_isRunning && !m_Window->isClosed()) {
        if(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Sleep(1);
    }
}

void Game::quit() {
    m_isRunning = false;
}
