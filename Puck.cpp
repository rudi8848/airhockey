#include "Puck.hpp"

void 	Puck::initPosition()
{
	setPosition(WINDOW_WIDTH /2, WINDOW_HEIGHT /2 );
}
int     Puck::getW() const
{
	return PUCK_WIDTH;
}
void 	Puck::move(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{

    int x = getX();
    int y = getY();

    x += xVel;
    y += yVel;

    if (x < BORDER_WIDTH )
    {
       xVel = -xVel;
       x = BORDER_WIDTH;
    }
    else if (x > WINDOW_WIDTH - BORDER_WIDTH - PUCK_WIDTH)
    {
        x = WINDOW_WIDTH - BORDER_WIDTH - PUCK_WIDTH;
        xVel = -xVel;
    }
    if (y < BORDER_WIDTH)
    {
        yVel = -yVel;
        y = BORDER_WIDTH;
    }
    else if (y > WINDOW_HEIGHT - BORDER_WIDTH - PUCK_WIDTH)
    {
        y =  WINDOW_HEIGHT - BORDER_WIDTH - PUCK_WIDTH;
        yVel = -yVel;
    }
    setPosition(x, y);
}


void 	Puck::move(Mix_Chunk *chunk)
{

    int x = getX();
    int y = getY();

    x += xVel;
    y += yVel;

    if (x < BORDER_WIDTH )
    {
        Mix_PlayChannel(-1, chunk, 0);
       xVel = -xVel;
       x = BORDER_WIDTH;
    }
    else if (x > WINDOW_WIDTH - BORDER_WIDTH - PUCK_WIDTH)
    {
    Mix_PlayChannel(-1, chunk, 0);
        x = WINDOW_WIDTH - BORDER_WIDTH - PUCK_WIDTH;
        xVel = -xVel;
    }
    if (y < BORDER_WIDTH)
    {
    Mix_PlayChannel(-1, chunk, 0);
        yVel = -yVel;
        y = BORDER_WIDTH;
    }
    else if (y > WINDOW_HEIGHT - BORDER_WIDTH - PUCK_WIDTH)
    {
    Mix_PlayChannel(-1, chunk, 0);
        y =  WINDOW_HEIGHT - BORDER_WIDTH - PUCK_WIDTH;
        yVel = -yVel;
    }
    setPosition(x, y);
}
