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

    Mix_FreeMusic(music);
    music = nullptr;

    //Mix_FreeChunk(hit);
    //hit = nullptr;

    Mix_Quit();
    SDL_Quit();
}
