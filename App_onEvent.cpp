#include "App.hpp"

void App::onEvent(SDL_Event* e)
{
    if (e->type == SDL_QUIT)
    {
        _running = false;
    }
}
