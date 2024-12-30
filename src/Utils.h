//
// Created by el on 12/30/24.
//

#ifndef BEZIER_CURVE_SDL_UTILS_H
#define BEZIER_CURVE_SDL_UTILS_H

#include <iostream>
#include "SDL.h"


namespace Utils{
    void inline SDLErr(){
        const char* msg = SDL_GetError();
        std::cerr << msg << std::endl;
    }

    int inline lerp(int a, int b, double t){
        return a + (b - a) * t;
    }

    Vec2 inline lerp(Vec2 a, Vec2 b, double t){
        return a + (b - a) * t;
    }
}


#endif //BEZIER_CURVE_SDL_UTILS_H
