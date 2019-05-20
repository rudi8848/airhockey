#ifndef SURFACE_H
#define SURFACE_H

#include <SDL2/SDL.h>

class Surface
{
    public:
    Surface();
    // image loading
    static SDL_Surface* loadSurface(char *fname, SDL_Surface* screen);
    static SDL_Surface* loadSurface(char *fname, SDL_Surface* screen, int r, int g, int b);
    //rendering
    static void drawSurface(SDL_Surface* src,SDL_Surface* dst, SDL_Rect* clip, int x, int y);
    static void drawSurface(SDL_Surface* src,SDL_Surface* dst, int x, int y);
    static void drawSurface(SDL_Surface* src,SDL_Surface* dst, SDL_Rect* clip,SDL_Rect* scale);

    private:

};

#endif // SURFACE_H
