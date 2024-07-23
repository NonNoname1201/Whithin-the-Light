//
// Created by User on 21.07.2024.
//

#include <OGL3D/Game/Game.h>
#include <OGL3D/Window/Window.h>
#include <OGL3D/Graphics/GraphicsEngine.h>
#include <memory>
#include <cstdlib>

Game::Game() {
    m_GraphicsEngine = std::make_unique<GraphicsEngine>();
    m_Window = std::make_unique<Window>();

    m_Window->makeCurrentContext();
    m_GraphicsEngine->setViewport(m_Window->getInnerSize());
}

Game::~Game() = default;

void Game::quit() {
    m_isRunning = false;
}

void Game::onCreate() {

}

void Game::onUpdate() {
    m_GraphicsEngine->clear({0.3, 0.5, 0.7, 1});

    m_Window->present(false);
}

void Game::onQuit() {

}
