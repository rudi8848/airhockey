#ifndef ROOM_H
#define ROOM_H

#include <SDL_mixer.h>
#include "Event.hpp"
#include "defines.hpp"
#include "InitError.hpp"
#include "Surface.hpp"

class Room : Event
{
    public:
        Room(SDL_Surface* scr = nullptr, int rwidth = WINDOW_WIDTH, int rheight = WINDOW_HEIGHT);
        virtual ~Room();

    virtual void loadMusic(std::string const& fname);
    virtual int onEvent(SDL_Event *e);
    virtual int onExit();

    /*  Main loop functions      */
    virtual void onLoop();
    virtual void onRender();
    virtual void move_camera(int lwidth);

    void loadBackground(std::string const& fname);
    void setCamera(int left, int top, int right, int bottom);
    void setHSpeed(int spd);
    void setVSpeed(int spd);

    private:
        Mix_Music *music;
        SDL_Surface *screen;
        SDL_Surface *background;
        SDL_Rect camera;
        int hspeed;
        int vspeed;
};

#endif
