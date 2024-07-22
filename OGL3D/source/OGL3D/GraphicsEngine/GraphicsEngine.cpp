//
// Created by User on 22.07.2024.
//

#include <OGL3D/GraphicsEngine/GraphicsEngine.h>
#include <glad/glad.h>
#include <cassert>
#include <stdexcept>

void GraphicsEngine::clear(const Vect4 &color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}