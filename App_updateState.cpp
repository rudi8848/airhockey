#include "App.hpp"


void App::updateState()
{
    if (next_state != STATE_NULL)
    {
        delete room;
        room = nullptr;

        Mix_PlayChannel(-1, menu, 0);

        switch (next_state)
        {
            case MENU:
            {
                new Menu(screen, WINDOW_WIDTH, WINDOW_HEIGHT);
                room->loadBackground("Backgrounds/menuBack.png");
                room->loadMusic("Sounds/Syntheticity.mid");
                break;
            }
            case PLAY:
            {
                room = new Match(screen, WINDOW_WIDTH, WINDOW_HEIGHT);
                room->loadBackground("Backgrounds/backGame.bmp");
                room->loadMusic("Sounds/Unknown.mid");

                break;
            }
            case OVER:
            {
                break;
            }
            default:
                break;
        }
        id_state = next_state;
        next_state = STATE_NULL;

    }
}
