#ifndef MATCH_H
#define MATCH_H

#include "Room.hpp"
#include "Enemy.hpp"

class Match: public Room
{
    public:
        Match(SDL_Surface* scr = nullptr, int rwidth = WINDOW_WIDTH, int rheight = WINDOW_HEIGHT);
        virtual ~Match();

        virtual int onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
        virtual void onLoop();
        virtual void onRender();
};

#endif // MATCH_H
