#include "App.hpp"

void App::onRender()
{
	std::cerr << __FUNCTION__ << std::endl;
    Surface::drawSurface(background, screen, 0, 0);

    SDL_UpdateWindowSurface(window);
}
