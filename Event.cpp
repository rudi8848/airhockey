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


        default:
            break;
    }
}

void Event::onExit()
{

}
