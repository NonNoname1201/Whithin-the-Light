//
// Created by User on 22.07.2024.
//

#ifndef WITHIN_THE_LIGHT_PREREQUISITES_H
#define WITHIN_THE_LIGHT_PREREQUISITES_H

#include <memory>

class VertexArrayObject;
typedef std::shared_ptr<VertexArrayObject> VertexArrayObjectPtr;

typedef float fPointSmall;
typedef double fPointBig;
typedef int integerStandard; // May be changed to short / long based on application needs
typedef unsigned int uIntegerStandard; // May be changed to ushort / ulong based on application needs


struct VertexBufferData{
    void* verticesList = nullptr;
    uIntegerStandard vertexSize = 0;
    uIntegerStandard listSize = 0;
};

#endif //WITHIN_THE_LIGHT_PREREQUISITES_H
