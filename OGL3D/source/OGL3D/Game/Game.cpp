//
// Created by User on 21.07.2024.
//

#include <OGL3D/Game/Game.h>
#include <OGL3D/Window/Window.h>
#include <OGL3D/GraphicsEngine/GraphicsEngine.h>
#include <Windows.h>

#include <memory>

Game::Game() {
    m_GraphicsEngine = std::make_unique<GraphicsEngine>();
    m_Window = std::make_unique<Window>();

    m_Window->makeCurrentContext();
}

Game::~Game() = default;

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

void Game::quit() {
    m_isRunning = false;
}

void Game::onCreate() {
    m_GraphicsEngine->clear({0.3, 0.5, 0.7, 1});

    m_Window->present(false);
}

void Game::onUpdate() {

}

void Game::onQuit() {

}
