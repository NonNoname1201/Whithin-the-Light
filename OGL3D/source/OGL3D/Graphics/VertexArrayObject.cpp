//
// Created by User on 23.07.2024.
//

#include <OGL3D/Graphics/VertexArrayObject.h>
#include <glad/glad.h>

VertexArrayObject::VertexArrayObject(const VertexBufferData &vertexBufferData) {
    glGenBuffers(1, &m_vertexBufferId);

    glGenVertexArrays(1, &m_vertexArrayObjectId);

    glBindVertexArray(m_vertexArrayObjectId);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, vertexBufferData.vertexSize * vertexBufferData.listSize,
                 vertexBufferData.verticesList, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexBufferData.vertexSize, 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

}

VertexArrayObject::~VertexArrayObject() {
    glDeleteBuffers(1, &m_vertexBufferId);
    glDeleteVertexArrays(1, &m_vertexArrayObjectId);
}

uIntegerStandard VertexArrayObject::getVertexArrayObjectId() {
    return m_vertexArrayObjectId;
}
