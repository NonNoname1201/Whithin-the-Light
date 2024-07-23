//
// Created by User on 22.07.2024.
//

#include <OGL3D/Graphics/GraphicsEngine.h>
#include <OGL3D/Graphics/VertexArrayObject.h>
#include <glad/glad.h>
#include <cassert>
#include <stdexcept>

void GraphicsEngine::clear(const Vect4 &color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsEngine::setViewport(const Rect &size) {
    glViewport(size.left, size.top, size.width, size.height);
}

VertexArrayObjectPtr GraphicsEngine::createVertexArrayObject(const VertexBufferData &vertexBufferData) {
    return std::make_shared<VertexArrayObject>(vertexBufferData);
}

void GraphicsEngine::setVertexArrayObject(const VertexArrayObjectPtr &vertexArrayObject) {
    glBindVertexArray(vertexArrayObject->getVertexArrayObjectId());
}

void GraphicsEngine::drawPolygon(uIntegerStandard vertexCount, uIntegerStandard offset) {

    glDrawArrays(GL_TRIANGLES, offset, vertexCount);

}
