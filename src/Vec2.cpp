//
// Created by el on 12/30/24.
//

#include "Vec2.h"

Vec2::Vec2(): x(0.0), y(0.0) {}
Vec2::Vec2(double x, double y): x(x), y(y) {}

Vec2 Vec2::operator - (const Vec2 &v) const {
    return {x - v.x, y - v.y};
}
Vec2 Vec2::operator + (const Vec2 &v) const{
    return {x + v.x, y + v.y};
}

Vec2 Vec2::operator * (const double & k) const{
    return {x * k, y * k};
}
