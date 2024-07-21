//
// Created by User on 21.07.2024.
//

#ifndef UNTITLED_WINDOW_H
#define UNTITLED_WINDOW_H

class Window {
public:
    Window();

    ~Window();

    void onDestroy();

    bool isClosed();

private:
    void* m_WindowHandle = nullptr;
};


#endif //UNTITLED_WINDOW_H
