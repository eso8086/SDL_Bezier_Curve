
#ifndef BEZIER_CURVE_SDL_APPLICATION_H
#define BEZIER_CURVE_SDL_APPLICATION_H

#include "SDL.h"
#include "Bezier.h"

struct Application{
private:
    SDL_Event event;
    Uint8 refresh_rate = 0;
    Vec2 mousePosition;
public:
    static SDL_DisplayMode displayMode;
    bool running = false;
    Application() = default;
    ~Application() = default;
    void Setup(int width, int height, const char* title, Uint8 refresh_rate);
    void Input();
    void Update();
    void Render();
    void Destroy();
};

#endif //BEZIER_CURVE_SDL_APPLICATION_H
