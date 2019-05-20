#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include "Surface.hpp"
#include "defines.hpp"


class App
{
    public:
        App();
        virtual ~App();

        int onExecute();

    private:
        bool    _running;

        SDL_Window*     window;
        SDL_Surface*    screen;
        SDL_Surface*    background;

        bool onInit();
        void onEvent(SDL_Event* e);
        void onLoop();
        void onRender();
        void onQuit();

};

#endif
