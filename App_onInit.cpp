#include "App.hpp"

bool App::onInit()
{
    int flags = IMG_INIT_PNG;
    int initted = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }
    window = SDL_CreateWindow(WINDOW_CAPTION, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window)
    {
        return false;
    }

    screen = SDL_GetWindowSurface(window);
    if (!screen)
    {
        return false;
    }
    SDL_SetSurfaceRLE(screen, 1);

    initted = IMG_Init(flags);
    if ((initted & flags) != flags)
        return false;
    if (TTF_Init() == -1)
        return false;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)  == -1)
        return false;

   font = TTF_OpenFont("Fonts/CuteFont-Regular.ttf", 64);
   if (!font)
   {
        return false;
    }
    menu = Mix_LoadWAV("Sounds/Menu_Backup05.wav");
    if (!menu)
        return false;
    return true;
}

bool    App::LoadMedia()
{
/*    menu = Mix_LoadWAV("Sounds/Menu_Backup05.wav");
    if (!menu)
        return false;
    hit1 = Mix_LoadWAV("Sounds/AirHockey_MalletHitPuck01.wav");
    if (!hit1)
        return false;
    hit2 = Mix_LoadWAV("Sounds/AirHockey_MalletHitPuck03.wav");
    if (!hit2)
        return false;
    hit3 = Mix_LoadWAV("Sounds/AirHockey_PuckHitSide02.wav");
    if (!hit3)
        return false;
    goal = Mix_LoadWAV("Sounds/AirHockey_GoalScore01.wav");
    if (!goal)
        return false;
  */
    return true;
}
