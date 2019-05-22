#ifndef APP_H
#define APP_H

#include <iostream>
//#include <SDL_stdinc.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "Event.hpp"
#include "Surface.hpp"
#include "defines.hpp"
#include "Player.hpp"
#include "Enemy.hpp"


class App : public Event
{
    public:
        App();
        virtual ~App();

        int onExecute();
        virtual void onEvent(SDL_Event *e);
        virtual void onExit();
        virtual void onWindowExposed();

        virtual void move(SDL_Keycode sym, Uint16 mod, Uint16 scancode);

    private:
        bool    _running;

        SDL_Window*     window;
        SDL_Surface*    screen;
        SDL_Surface*    background;


        Player*         player;
        Enemy*          enemy;
        //SDL_Surface*    player_x;
        //SDL_Surface*    player_y;
        SDL_Surface*    puck;

        Mix_Music*  music;
        Mix_Chunk*  hit;

        bool onInit();
        void onLoop();
        void onRender();
        void onQuit();
        bool checkScore();

};

#endif
