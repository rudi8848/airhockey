#include "App.hpp"

void    App::onStart()
{
    id_state = MENU;

    room = new Menu(screen, WINDOW_WIDTH, WINDOW_HEIGHT);
    room->loadBackground("Backgrounds/menuBack.png");
    room->loadMusic("Sounds/Syntheticity.mid");
    Surface::drawTextSurface("Fonts/CuteFont-Regular.ttf", screen, "Press SPACE to play", 100, 400, 255, 255, 255);
}
