//
// Created by el on 12/30/24.
//

#ifndef BEZIER_CURVE_SDL_VEC2_H
#define BEZIER_CURVE_SDL_VEC2_H

struct Vec2{
    double x;
    double y;

    Vec2();
    Vec2(double x, double y);
    Vec2 operator - (const Vec2& v) const;
    Vec2 operator + (const Vec2& v2) const;
    Vec2 operator * (const double & k) const;
    ~Vec2() = default;
};
#endif //BEZIER_CURVE_SDL_VEC2_H
