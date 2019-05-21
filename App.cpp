#include "App.hpp"

App::App()
{
    _running = true;
    window = nullptr;
    screen = nullptr;
    background = nullptr;
    player_x = nullptr;
    player_y = nullptr;
}

App::~App()
{

}

int App::onExecute()
{
    if (onInit() == false)
        return -1;

    SDL_Event e;

    while (_running)
    {
        while (SDL_PollEvent(&e))
        {
            onEvent(&e);
        }
        //onRender();
        onLoop();
    }

    onQuit();
    return 0;
}


