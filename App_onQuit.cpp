#include "App.hpp"

void App::onQuit()
{
    SDL_FreeSurface(screen);
    screen = nullptr;
    SDL_FreeSurface(background);
    background = nullptr;
    /*
    SDL_FreeSurface(player_x);
    player_x = nullptr;
    SDL_FreeSurface(player_y);
    player_y = nullptr;
    */
    SDL_FreeSurface(puck);
    puck = nullptr;

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}
