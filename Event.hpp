#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>

class Event
{
    public:
    Event();
    virtual ~Event();

    virtual void onEvent(SDL_Event *e);
    virtual void onExit();

    private:

};

#endif // EVENT_H
