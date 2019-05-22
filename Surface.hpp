#ifndef SURFACE_H
#define SURFACE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class Surface
{
    public:
    Surface();
    // image loading
    static SDL_Surface* loadSurface(std::string const& fname, SDL_Surface* screen);
    static SDL_Surface* loadSurface(std::string const& fname, SDL_Surface* screen, int r, int g, int b);
    //rendering
    static void drawSurface(SDL_Surface* src,SDL_Surface* dst, SDL_Rect* clip, int x, int y);
    static void drawSurface(SDL_Surface* src,SDL_Surface* dst, int x, int y);
    static void drawSurface(SDL_Surface* src,SDL_Surface* dst, SDL_Rect* clip,SDL_Rect* scale);
    static void drawTextSurface(TTF_Font *font, SDL_Surface* screen, std::string const & str, int x, int y, int r, int g, int b);

    static void clearSurface(SDL_Surface* screen, int r, int g, int b);
    private:

};

#endif // SURFACE_H
