#ifndef APP_H
#define APP_H

#include <iostream>

//#include <SDL2/SDL.h>
#include "Event.hpp"
#include "Surface.hpp"
#include "defines.hpp"
#include "Player.hpp"


class App : public Event
{
    public:
        App();
        virtual ~App();

        int onExecute();
        virtual void onEvent(SDL_Event *e);
        virtual void onExit();
        virtual void onWindowExposed();

    private:
        bool    _running;

        SDL_Window*     window;
        SDL_Surface*    screen;
        SDL_Surface*    background;

        Player*         player;
        Player*         enemy;
        //SDL_Surface*    player_x;
        //SDL_Surface*    player_y;
        SDL_Surface*    puck;

        bool onInit();
        void onLoop();
        void onRender();
        void onQuit();

};

#endif
