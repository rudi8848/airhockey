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

                std::cerr << __PRETTY_FUNCTION__<< std::endl;
        Player  player("Backgrounds/player1.bmp");
        Enemy enemy("Backgrounds/player2.bmp");

        player.init(screen);
        enemy.init(screen);

        Surface::drawSurface(player.getSurface(),screen, player.getX(), player.getY());
        Surface::drawSurface(enemy.getSurface(), screen, enemy.getX(), enemy.getY());
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
