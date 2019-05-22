#include "Match.hpp"

Match::Match(SDL_Surface* scr, int rwidth, int rheight) : Room(scr, rwidth, rheight)
{
    this->text = "Score: ";
    this->text_x = 120;
    this->text_y = 30;
    this->r = 255;
    this->g = 0;
    this->b = 0;
}

Match::~Match()
{

}

int Match::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    int ret = STATE_NULL;

    switch(sym)
    {
        case SDLK_ESCAPE:
        {
            ret = EXIT;
            break;
        }
        /*
        case SDLK_SPACE:
        {
            ret = PLAY;
            break;
        }
        */
        default:
        {
            ret = STATE_NULL;
            break;
        }
    }
    return ret;
}

void Match::onLoop()
{

}

void Match::onRender()
{
    Room::onRender();
}

