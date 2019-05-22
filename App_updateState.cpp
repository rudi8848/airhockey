#include "App.hpp"


void App::updateState()
{
    if (next_state != STATE_NULL)
    {
        delete room;
        room = nullptr;

        switch (next_state)
        {
            case MENU:
            {
                break;
            }
            case PLAY:
            {
                break;
            }
            case PAUSED:
            {
                break;
            }
        }
        id_state = next_state;
        next_state = STATE_NULL;
    }
}
