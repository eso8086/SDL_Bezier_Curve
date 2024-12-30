//
// Created by el on 12/30/24.
//

#include <vector>
#include "Bezier.h"
#include "Graphics.h"
#include "Vec2.h"
#include "Utils.h"
std::vector<Vec2> Bezier::GetLinear(Vec2 p0, Vec2 p1) {
    int radius = 10;

    //draw points
    Graphics::DrawFilledCircle(p0.x, p0.y, radius, 0xFF00FFFF);
    Graphics::DrawFilledCircle(p1.x, p1.y, radius, 0xFF00FFFF);


    std::vector<Vec2> points;
    double step = 0.1;
    double numSteps = static_cast<int>(1.0 / step) + 1;
    for(int i = 0; i <= numSteps; ++i){
        double t = (i < numSteps) ? i * step : 1.0;
        points.push_back(Utils::lerp(p0, p1, t));
    }

    return points;
}

std::vector<Vec2> Bezier::GetQuadratic(Vec2 p0, Vec2 c0, Vec2 p1) {
    std::vector<Vec2> points;
    double step = 0.01;
    int numSteps = static_cast<int>(1.0 / step) + 1;
    for(int i = 0; i <= numSteps; ++i){
        double t = (i < numSteps) ? i * step : 1.0;

//        Vec2 l01 = Utils::lerp(p0, c0, t);
//        Vec2 l12 = Utils::lerp(c0, p1, t);
//
//        points.push_back(Utils::lerp(l01, l12, t));

        double x = (1-t)*(1-t)*p0.x+2*(1-t)*t*c0.x+t*t*p1.x;
        double y = (1-t)*(1-t)*p0.y+2*(1-t)*t*c0.y+t*t*p1.y;
        points.emplace_back(Vec2({x, y}));
    }
    return points;
}

