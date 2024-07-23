//
// Created by User on 21.07.2024.
//

#ifndef WITHIN_THE_LIGHT_WINDOW_H
#define WITHIN_THE_LIGHT_WINDOW_H

#include <OGL3D/Math/Rect.h>

class Window {
public:
    Window();

    ~Window();

    Rect getInnerSize();

    void makeCurrentContext();
    void present(bool vSync);

private:
    void *m_WindowHandle = nullptr;
    void *m_WindowDC = nullptr;
};


#endif //WITHIN_THE_LIGHT_WINDOW_H
