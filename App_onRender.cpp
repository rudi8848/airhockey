#include "App.hpp"

void App::onRender()
{
    Surface::drawSurface(background, screen, 0, 0);

    Surface::drawSurface(player->getSurface(), screen, player->getX(), player->getY());
    Surface::drawSurface(enemy->getSurface(), screen,  enemy->getX(), enemy->getY());
     /*		TEMP	*/
    Surface::drawSurface(puck, screen, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    /*		***		*/
    SDL_UpdateWindowSurface(window);
}
