#include "App.hpp"

void App::onEvent(SDL_Event* e)
{
    Event::onEvent(e);
}

void App::onExit()
{
    _running = false;
}

void App::onWindowExposed()
{
    onRender();
}
