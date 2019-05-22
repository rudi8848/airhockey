#include "App.hpp"

void App::onLoop()
{
    if (room)
        room->onLoop();
}
