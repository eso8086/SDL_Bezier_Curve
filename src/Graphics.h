//
// Created by el on 12/28/24.
//

#ifndef BEZIER_CURVE_SDL_GRAPHICS_H
#define BEZIER_CURVE_SDL_GRAPHICS_H

#include <vector>
#include "SDL.h"
#include "Vec2.h"
#include "SDL2_gfxPrimitives.h"

struct Graphics{
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static bool OpenWindow(int width, int height, const char* title, Uint8 refresh_rate);
    static void CloseWindow();

    static void ClearScreen(Uint32 color);
    static void RenderFrame();

    static void DrawFilledCircle(double x, double y, double radius, Uint32 color);
    static void DrawLine(double x0, double y0, double x1, double y1, Uint32 color);

    static void DrawQuadraticBezier(double x0, double y0, double c0x, double c0y, double x2, double y2);
    static void DrawQuadraticBezier(Vec2 p0, Vec2 c0, Vec2 p2);
};

#endif //BEZIER_CURVE_SDL_GRAPHICS_H
