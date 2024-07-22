//
// Created by User on 22.07.2024.
//

#ifndef WITHIN_THE_LIGHT_VECT4_H
#define WITHIN_THE_LIGHT_VECT4_H

#include "OGL3D/Prerequisites.h"

class Vect4 {
public:
    Vect4(){}
    Vect4(fPointSmall x, fPointSmall y, fPointSmall z, fPointSmall w) : x(x), y(y), z(z), w(w) {}
    ~Vect4(){}

public:
    fPointSmall x = 0, y = 0, z = 0, w = 0;
};

#endif //WITHIN_THE_LIGHT_VECT4_H
