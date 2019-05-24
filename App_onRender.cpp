#include "App.hpp"

void App::onRender()
{
    Surface::clearSurface(screen, 0, 0, 0);
    room->onRender();

    Surface::drawTextSurface(font, screen, room->text, room->text_x, room->text_y, room->r, room->g, room->b);

    SDL_UpdateWindowSurface(window);
}
