#include "Match.hpp"

Match::Match(SDL_Surface* scr, int rwidth, int rheight) : Room(scr, rwidth, rheight)
{

}

Match::~Match()
{

}

int Match::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    int ret = STATE_NULL;

    return ret;
}

void Match::onLoop()
{

}

void Match::onRender()
{
    Room::onRender();
}
