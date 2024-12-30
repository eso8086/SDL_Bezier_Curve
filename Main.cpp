#include "src/Application.h"



int main(int argc, char* args[]) {
    Application app;

    //optional refresh rate otherwise default monitor rf will be used
    Uint8 refresh_rate = 120;

    int window_w = 500, window_h = 500;
    const char* window_title = "SDL Bezier Curve";

    app.Setup(window_w, window_h, window_title, refresh_rate);

    while(app.running){
        app.Input();
        app.Update();
        app.Render();
    }

    app.Destroy();

    return 0;
}
