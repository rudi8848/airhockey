#include "App.hpp"

void App::onRender()
{
	//std::cerr << __FUNCTION__ << std::endl;
    Surface::drawSurface(background, screen, 0, 0);
   /*		TEMP	*/
    //Surface::drawSurface(player_x, screen, BORDER_WIDTH, BORDER_WIDTH);
    Surface::drawSurface(player->getSurface(), screen, player->getX(), player->getY());
    Surface::drawSurface(enemy->getSurface(), screen,  enemy->getX(), enemy->getY());
    //Surface::drawSurface(player_y, screen, WINDOW_WIDTH - STRIKER_WIDTH - BORDER_WIDTH, WINDOW_HEIGHT - STRIKER_WIDTH - BORDER_WIDTH);
    Surface::drawSurface(puck, screen, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    /*		***		*/
    SDL_UpdateWindowSurface(window);
}
