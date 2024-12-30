//
// Created by el on 12/28/24.
//

#include "Graphics.h"
#include "Application.h"
#include <iostream>
#include "Utils.h"

SDL_Window* Graphics::window = nullptr;
SDL_Renderer* Graphics::renderer = nullptr;



bool Graphics::OpenWindow(int width, int height, const char* title, Uint8 refresh_rate){
    int centerX = Application::displayMode.w / 2 - width / 2;
    int centerY = Application::displayMode.h / 2 - width / 2;

    window = SDL_CreateWindow(title, centerX, centerY, width, height, 0);
    if(!window){
        std::cerr << "Error creating SDL window" << std::endl;
        Utils::SDLErr();
        return false;
    }
    Uint32 flags = SDL_RENDERER_ACCELERATED;
    if(refresh_rate == Application::displayMode.refresh_rate){
        flags |= SDL_RENDERER_PRESENTVSYNC;
    }
    renderer = SDL_CreateRenderer(window, -1, flags);
    if(!renderer){
        std::cerr << "Error creating SDL renderer";
        Utils::SDLErr();
        return false;
    }
    return true;
}

void Graphics::CloseWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphics::ClearScreen(Uint32 color) {
    SDL_SetRenderDrawColor(renderer, color >> 16, color >> 8, color, 255);
    SDL_RenderClear(renderer);
}

void Graphics::RenderFrame(){
    SDL_RenderPresent(renderer);
}

void Graphics::DrawFilledCircle(double x, double y, double radius, Uint32 color) {
    filledCircleColor(renderer, x, y, radius, color);
}

void Graphics::DrawLine(double x0, double y0, double x1, double y1, Uint32 color) {
    lineColor(renderer, x0, y0, x1, y1, color);
}
void Graphics::DrawQuadraticBezier(Vec2 p0, Vec2 c0, Vec2 p2) {
    int radius = 10;

    //draw points
    Graphics::DrawFilledCircle(p0.x, p0.y, radius, 0xFF00FFFF);
    Graphics::DrawFilledCircle(c0.x, c0.y, radius, 0xFF00FFFF);
    Graphics::DrawFilledCircle(p2.x, p2.y, radius, 0xFF00FFFF);

    auto points = Bezier::GetQuadratic(p0, c0, p2);

    for(int i = 0; i < points.size() - 1; i++){
        Vec2 p0 = points[i];
        Vec2 p1 = points[i+1];
        Graphics::DrawLine(p0.x, p0.y, p1.x, p1.y, 0xFF0000FF);
    }
}

void Graphics::DrawQuadraticBezier(double x0, double y0, double c0x, double c0y, double x2, double y2) {
    DrawQuadraticBezier({x0, y0}, {c0x, c0y}, {x2, y2});
}
