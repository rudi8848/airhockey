#include "Surface.hpp"

Surface::Surface()
{
}

SDL_Surface *Surface::loadSurface(char *fname, SDL_Surface* screen)
{
    SDL_Surface* temp = SDL_LoadBMP(fname);
    if (!temp)
        return nullptr;
    SDL_Surface* newSurface = SDL_ConvertSurface(temp, screen->format, 0);

    SDL_FreeSurface(temp);
    return newSurface;
}

SDL_Surface *Surface::loadSurface(char *fname, SDL_Surface* screen, int r, int g, int b)
{
    SDL_Surface* temp = SDL_LoadBMP(fname);
    if (!temp)
        return nullptr;
    SDL_Surface* newSurface = SDL_ConvertSurface(temp, screen->format, 0);
    SDL_SetColorKey(newSurface, SDL_TRUE, SDL_MapRGB(newSurface->format, r, g, b));
    SDL_FreeSurface(temp);
    return newSurface;
}


void Surface::drawSurface(SDL_Surface* src,SDL_Surface* dst, int x, int y)
{
    if (!src || !dst)
        return;

    SDL_Rect rcDest;

    rcDest.x = x;
    rcDest.y = y;

    SDL_BlitSurface(src, NULL, dst, &rcDest);
}

void Surface::drawSurface(SDL_Surface* src,SDL_Surface* dst, SDL_Rect* clip, int x, int y)
{
    if (!src || !dst)
        return;

    SDL_Rect rcDest;

    rcDest.x = x;
    rcDest.y = y;

    SDL_BlitSurface(src, clip, dst, &rcDest);
}

void Surface::drawSurface(SDL_Surface* src,SDL_Surface* dst, SDL_Rect* clip, SDL_Rect* scale)
{
    if (!src || !dst)
        return;

    SDL_BlitSurface(src, clip, dst, scale);
}