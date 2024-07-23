//
// Created by User on 23.07.2024.
//

#ifndef WITHIN_THE_LIGHT_RECT_H
#define WITHIN_THE_LIGHT_RECT_H

#include <OGL3D/Prerequisites.h>

class Rect {
public:
    Rect() {}

    Rect(uIntegerStandard width, uIntegerStandard height) : width(width), height(height) {}

    Rect(integerStandard x, integerStandard y, uIntegerStandard width, uIntegerStandard height) : left(x), top(y), width(width), height(height) {}

    Rect(const Rect &rect) : left(rect.left), top(rect.top), width(rect.width), height(rect.height) {}

    ~Rect() {}

public:
    integerStandard left = 0, top = 0, width = 0, height = 0;
};

#endif //WITHIN_THE_LIGHT_RECT_H
