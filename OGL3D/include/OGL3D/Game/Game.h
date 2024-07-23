//
// Created by User on 21.07.2024.
//

#ifndef WITHIN_THE_LIGHT_GAME_H
#define WITHIN_THE_LIGHT_GAME_H

#include <OGL3D/Window/Window.h>
#include <memory>

class Window;

class GraphicsEngine;

class Game {
public:
    Game();

    ~Game();


    virtual void onCreate();
    virtual void onUpdate();
    virtual void onQuit();


    void run();

    void quit();

protected:
    bool m_isRunning = true;
    std::unique_ptr<GraphicsEngine> m_GraphicsEngine;
    std::unique_ptr<Window> m_Window;

    VertexArrayObjectPtr m_vertexArrayObject;
};

#endif //WITHIN_THE_LIGHT_GAME_H
