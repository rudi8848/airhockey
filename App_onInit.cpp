#include "App.hpp"

bool App::onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL initialization error: " << SDL_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow(WINDOW_CAPTION, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window)
    {
        std::cout << "SDL initialization error: " << SDL_GetError() << std::endl;
        return false;
    }

    screen = SDL_GetWindowSurface(window);
    if (!screen)
    {
        std::cout << "SDL initialization error: " << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetSurfaceRLE(screen, 1);
    background = Surface::loadSurface("Backgrounds/backGame.bmp",screen);
    //player_x = Surface::loadSurface("Backgrounds/player1.bmp",screen);
    //player_y = Surface::loadSurface("Backgrounds/player2.bmp",screen);
    puck = Surface::loadSurface("Backgrounds/puck.bmp",screen, 255, 0, 216);
    if (!background || /*!player_x || !player_y ||*/ !puck)
    {
        std::cerr << "SDL2 error: " << SDL_GetError() << std::endl;
        return false;
    }

    player = new Player("Backgrounds/player1.bmp");
    if (!player->init(screen))
        return false;
    enemy = new Enemy("Backgrounds/player2.bmp");
    if (!enemy->init(screen))
        return false;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << Mix_GetError() << std::endl;
        return false;
    }

    music = Mix_LoadMUS("Sounds/Unknown.mid");
    if (!music)
    {
        std::cerr << Mix_GetError() << std::endl;
        return false;
    }
    if (Mix_PlayMusic(music, -1) == -1)
        std::cerr << Mix_GetError() << std::endl;
    return true;
}
