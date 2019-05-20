#include "App.hpp"

void App::onRender()
{
    Surface::drawSurface(background, screen, 0, 0);

    SDL_UpdateWindowSurface(window);
}
