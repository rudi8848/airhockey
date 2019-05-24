#include "App.hpp"

void    App::onStart()
{

    id_state = MENU;

    room = new Menu(screen, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!room)
        throw InitError("Start error: ");

    room->loadBackground("Backgrounds/menuBack.png");
    room->loadMusic("Sounds/Syntheticity.mid");

}
