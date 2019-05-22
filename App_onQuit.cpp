#include "App.hpp"

void App::onQuit()
{
    if (room)
    {
        delete room;
        room = nullptr;
    }
    SDL_FreeSurface(screen);
    screen = nullptr;


    SDL_DestroyWindow(window);
    window = nullptr;



    Mix_Quit();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
