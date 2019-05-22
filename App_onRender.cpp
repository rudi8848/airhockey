#include "App.hpp"

void App::onRender()
{
    Surface::clearSurface(screen, 0, 0, 0);
    room->onRender();
    SDL_UpdateWindowSurface(window);
}
