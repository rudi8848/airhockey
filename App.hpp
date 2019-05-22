#ifndef APP_H
#define APP_H

#include <iostream>
#include <SDL.h>
#include "Room.hpp"
#include "Menu.hpp"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


//#include "InitError.hpp"
//#include "Surface.hpp"
//#include "Event.hpp"
//#include "defines.hpp"



class App
{
    public:
        App();
        virtual ~App();

        e_state onExecute();

        virtual void onExit();


    private:

        e_state id_state;
        e_state next_state;

        SDL_Window*     window;
        SDL_Surface*    screen;

        Room *room;

        void onStart();
        bool onInit();
        void onLoop();
        void onRender();
        void onQuit();
        void updateState();
        //bool checkScore();

};

#endif
