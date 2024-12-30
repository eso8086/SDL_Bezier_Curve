//
// Created by el on 12/28/24.
//

#include "Application.h"
#include "Graphics.h"
#include "SDL_events.h"
#include <iostream>
#include "Utils.h"

SDL_DisplayMode Application::displayMode;

void Application::Setup(int width, int height, const char* title, Uint8 _refresh_rate = 0) {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cerr << "Error Initializing SDL" << std::endl;
        Utils::SDLErr();
    }

    if(SDL_GetCurrentDisplayMode(0, &Application::displayMode) != 0){
        std::cerr << "Error Initializing SDL" << std::endl;
        Utils::SDLErr();
    }
    if(_refresh_rate != 0){
        refresh_rate = _refresh_rate;
    }
    else{
        refresh_rate = Application::displayMode.refresh_rate;
    }
    running = Graphics::OpenWindow(width, height, title, refresh_rate);
}

void Application::Destroy() {
    Graphics::CloseWindow();
}

void Application::Input() {
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    running = false;
                }
                break;
            case SDL_MOUSEMOTION:
                mousePosition = { (double) event.motion.x, (double) event.motion.y};
                break;
        }
    }
}

void Application::Render() {
    Graphics::ClearScreen(0xFF0F0721);

//    Graphics::DrawQuadraticBezier(50, 50, 300, 200, 400, 400);
    Graphics::DrawQuadraticBezier(50, 50, mousePosition.x, mousePosition.y, 400, 400);

    Graphics::RenderFrame();
}

void Application::Update() {
    static Uint32 previousTick = SDL_GetTicks();
    Uint8 eachFrameTime = 1000 / refresh_rate;
    Uint32 elapsedTime = SDL_GetTicks() - previousTick;

    if(refresh_rate != Application::displayMode.refresh_rate && eachFrameTime > elapsedTime){
        std::cout << eachFrameTime - elapsedTime << std::endl;
        SDL_Delay(eachFrameTime - elapsedTime);
    }

    float deltaT = 0;
    if(SDL_GetTicks() - previousTick > eachFrameTime){
        deltaT = eachFrameTime;
    }
    deltaT /= 1000.0f; //ms to seconds

    previousTick = SDL_GetTicks();
}