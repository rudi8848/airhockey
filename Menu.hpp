#ifndef MENU_H
#define MENU_H

#include "Room.hpp"

class Menu: public Room
{
    public:
        Menu(SDL_Surface* scr = nullptr, int rwidth = WINDOW_WIDTH, int rheight = WINDOW_HEIGHT);
        virtual ~Menu();

        virtual int onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
        virtual void onLoop();
        virtual void onRender();

};

#endif // MENU_H
