#include "Event.hpp"

Event::Event()
{

}

Event::~Event()
{

}

void Event::onEvent(SDL_Event *e)
{
    switch(e->type)
    {
        case SDL_QUIT:
        {
            onExit();
            break;
        }
        case SDL_KEYDOWN:
        {
            onKeyDown(e->key.keysym.sym, e->key.keysym.mod, e->key.keysym.scancode);
            break;
        }
        case SDL_KEYUP:
        {
            onKeyUp(e->key.keysym.sym, e->key.keysym.mod, e->key.keysym.scancode);
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            switch (e->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                    onLButtonDown(e->button.x, e->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT:
                {
                    onRButtonDown(e->button.x, e->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE:
                {
                    onMButtonDown(e->button.x, e->button.y);
                    break;
                }
            }
            break;
        }
        case SDL_MOUSEMOTION:
        {
            onMouseMove(e->motion.x, e->motion.y, e->motion.xrel, e->motion.yrel, (e->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,(e->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,(e->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0 );
            break;
        }

        default:
            break;
    }
}

void Event::onExit()
{

}

void Event::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    switch(sym)
    {
        case SDLK_ESCAPE:
        {
            onExit();
            break;
        }
    }
}

void Event::onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{

}

void Event::onLButtonDown(int xm, int ym)
{

}

void Event::onRButtonDown(int xm, int ym)
{

}

void Event::onMButtonDown(int xm, int ym)
{

}

void Event::onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle)
{

}
