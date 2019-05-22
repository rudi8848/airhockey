#include "Room.hpp"

Room::Room(SDL_Surface* scr, int rwidth, int rheight)
{

    screen = scr;
    background = nullptr;
    music = nullptr;

    camera.x = 0;
    camera.y = 0;
    camera.w = rwidth;
    camera.h = rheight;

    hspeed = 0;
    vspeed = 0;
}

Room::~Room()
{
    if (background)
    {
        SDL_FreeSurface(background);
        background = nullptr;
    }
    if (music)
    {
        Mix_FreeMusic(music);
        music = nullptr;
    }
}

void    Room::loadMusic(std::string const& fname)
{
    music = Mix_LoadMUS(fname.c_str());
    if (!music)
        throw InitError("Load Music Failed!");
    if (Mix_PlayMusic(music, -1) == -1)
        throw InitError("Playing music failed!");
}

int Room::onEvent(SDL_Event *e)
{
    int ret = 0;

    if (SDL_PollEvent(e))
    {
        ret = Event::onEvent(e);
    }
    return ret;
}


int Room::onExit()
{
    return EXIT;
}

void    Room::onLoop()
{

}

void    Room::onRender()
{
    Surface::drawSurface(background, screen, &camera, 0, 0);
}

void    Room::move_camera(int lwidth)
{
    camera.x += hspeed;
    camera.y += vspeed;

    if (camera.x + camera.w >= lwidth)
    {
        camera.x = lwidth - camera.w;
    }
}

void    Room::loadBackground(std::string const& fname)
{
    background = Surface::loadSurface(fname, screen);

    if (!background)
        throw InitError("Load Background Failed!");
}

void    Room::setCamera(int left, int top, int right, int bottom)
{
    camera.x = left;
    camera.y = top;
    camera.w = right;
    camera.h = bottom;
}

void    Room::setHSpeed(int spd)
{
    hspeed = spd;
}

void    Room::setVSpeed(int spd)
{
    vspeed = spd;
}

SDL_Surface *Room::getScreen() const
{
    return this->screen;
}
