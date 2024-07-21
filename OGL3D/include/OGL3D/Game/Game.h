//
// Created by User on 21.07.2024.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#include <OGL3D/Window/Window.h>
#include <memory>

class Game {
public:
    Game();

    ~Game();

    void run();
    void quit();

protected:
    bool m_isRunning = true;
    std::unique_ptr<Window> m_Window;
};
#endif //UNTITLED_GAME_H
