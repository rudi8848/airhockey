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
    virtual void onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
    virtual void onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
    virtual void onLButtonDown(int xm, int ym);
    virtual void onRButtonDown(int xm, int ym);
    virtual void onMButtonDown(int xm, int ym);
    virtual void onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle);

    private:

};

#endif // EVENT_H
