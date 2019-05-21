#include "App.hpp"

void App::onRender()
{
	//std::cerr << __FUNCTION__ << std::endl;
    Surface::drawSurface(background, screen, 0, 0);
    Surface::drawSurface(player_x, screen, BORDER_WIDTH, BORDER_WIDTH);
    Surface::drawSurface(player_y, screen, WINDOW_WIDTH - STRIKER_WIDTH - BORDER_WIDTH, WINDOW_HEIGHT - STRIKER_WIDTH - BORDER_WIDTH);

    SDL_UpdateWindowSurface(window);
}
