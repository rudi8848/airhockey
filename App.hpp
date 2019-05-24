#ifndef APP_H
#define APP_H

#include "defines.hpp"
#include "Menu.hpp"
#include "Match.hpp"
#include "Game.hpp"
#include <SDL_mixer.h>
#include <SDL_ttf.h>


class App
{
    public:
        App();
        virtual ~App();

        e_state onExecute();
        Mix_Chunk *menu;


    private:

        e_state id_state;
        e_state next_state;

        SDL_Window*     window;
        SDL_Surface*    screen;

        TTF_Font *font;

        Room *room;

        void onStart();
        bool onInit();
        void onLoop();
        void onRender();
        void onQuit();
        void updateState();

};

#endif
