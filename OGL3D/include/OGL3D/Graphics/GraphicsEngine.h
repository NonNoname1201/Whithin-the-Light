//
// Created by User on 22.07.2024.
//

#ifndef WITHIN_THE_LIGHT_GRAPHICSENGINE_H
#define WITHIN_THE_LIGHT_GRAPHICSENGINE_H

#include <OGL3D/Math/Vect4.h>
#include <OGL3D/Math/Rect.h>

class GraphicsEngine {
public:
    GraphicsEngine();
    ~GraphicsEngine();

public:
    void clear(const Vect4& color);
    void setViewport(const Rect& size);
};

#endif //WITHIN_THE_LIGHT_GRAPHICSENGINE_H