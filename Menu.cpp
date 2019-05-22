#include "Menu.hpp"

Menu::Menu(SDL_Surface* scr, int rwidth, int rheight) : Room(scr, rwidth, rheight)
{
    this->text = "Press SPACE to play";
    this->text_x = 120;
    this->text_y = 400;
    this->r = 255;
    this->g = 255;
    this->b = 255;
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
