//
// Created by el on 12/30/24.
//

#ifndef BEZIER_CURVE_SDL_BEZIER_H
#define BEZIER_CURVE_SDL_BEZIER_H

#include "Vec2.h"
#include <vector>

class Bezier {
public:
    static std::vector<Vec2> GetLinear(Vec2 p0, Vec2 p1);
    static std::vector<Vec2> GetQuadratic(Vec2 p0, Vec2 c0, Vec2 p1);
};


#endif //BEZIER_CURVE_SDL_BEZIER_H
