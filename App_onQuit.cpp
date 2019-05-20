#include "App.hpp"

void App::onQuit()
{
    SDL_FreeSurface(screen);
    SDL_FreeSurface(background);
    screen = nullptr;
    background = nullptr;

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}
