#include "App.hpp"

bool App::onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }
    window = SDL_CreateWindow(WINDOW_CAPTION, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window)
        return false;

    screen = SDL_GetWindowSurface(window);
    if (!screen)
        return false;

    SDL_SetSurfaceRLE(screen, 1);
    background = Surface::loadSurface("Backgrounds/backGame.bmp",screen);
    if (!background)
        return false;
    return true;
}
