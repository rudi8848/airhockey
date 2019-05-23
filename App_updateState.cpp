#include "App.hpp"


void App::updateState()
{
//std::cerr << __PRETTY_FUNCTION__<< std::endl;
    if (next_state != STATE_NULL)
    {
        delete room;
        room = nullptr;

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
            case PAUSED:
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
