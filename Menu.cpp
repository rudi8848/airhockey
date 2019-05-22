#include "Menu.hpp"

Menu::Menu(SDL_Surface* scr, int rwidth, int rheight) : Room(scr, rwidth, rheight)
{

}

Menu::~Menu()
{

}

int Menu::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    int ret = STATE_NULL;

    switch(sym)
    {
        case SDLK_ESCAPE:
        {
            ret = EXIT;
            break;
        }
        case SDLK_SPACE:
        {
            ret = PLAY;
            break;
        }
        default:
        {
            ret = STATE_NULL;
            break;
        }
    }
    return ret;
}

void Menu::onLoop()
{

}

void Menu::onRender()
{
    Room::onRender();
}
