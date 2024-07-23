//
// Created by User on 23.07.2024.
//

#ifndef WITHIN_THE_LIGHT_VERTEXARRAYOBJECT_H
#define WITHIN_THE_LIGHT_VERTEXARRAYOBJECT_H

#include <OGL3D/Prerequisites.h>

class VertexArrayObject {
public:
    VertexArrayObject(const VertexBufferData& vertexBufferData);
    ~VertexArrayObject();

    uIntegerStandard getVertexArrayObjectId();
private:
    uIntegerStandard m_vertexBufferId = 0;
    uIntegerStandard m_vertexArrayObjectId = 0;
};

#endif //WITHIN_THE_LIGHT_VERTEXARRAYOBJECT_H
