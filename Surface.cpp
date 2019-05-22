#include "Surface.hpp"

Surface::Surface()
{
}

SDL_Surface *Surface::loadSurface(std::string const & fname, SDL_Surface* screen)
{

    SDL_Surface* temp = IMG_Load(fname.c_str());
    if (!temp)
        return nullptr;
    SDL_Surface* newSurface = SDL_ConvertSurface(temp, screen->format, 0);

    SDL_FreeSurface(temp);
    return newSurface;
}

SDL_Surface *Surface::loadSurface(std::string const & fname, SDL_Surface* screen, int r, int g, int b)
{
    SDL_Surface* temp = IMG_Load(fname.c_str());
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

void Surface::clearSurface(SDL_Surface* screen, int r, int g, int b)
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, r, g, b));
}


void Surface::drawTextSurface(TTF_Font *font, SDL_Surface* screen, std::string const & str, int x, int y, int r, int g, int b)
{
    if (!font || !screen)
        return;
        std::cerr << __PRETTY_FUNCTION__ << std::endl;
    SDL_Color color = {r, g, b};

    SDL_Rect rcDest;
    rcDest.x = x;
    rcDest.y = y;

    SDL_Surface *txtSurface = TTF_RenderText_Solid(font, str.c_str(), color);
    if (!txtSurface)
        return;
    SDL_BlitSurface(txtSurface, NULL, screen, &rcDest);
    SDL_FreeSurface(txtSurface);

}
