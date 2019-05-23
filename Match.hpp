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
        virtual int onUser(Uint8 type, int code, void *data1, void *data2);
        virtual void onLoop();
        virtual void onRender();

        Mix_Chunk *hit1;
        Mix_Chunk *hit2;
        Mix_Chunk *hit3;
        Mix_Chunk *goal;
};

#endif // MATCH_H
