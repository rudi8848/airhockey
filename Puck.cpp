#include "Puck.hpp"

void 	Puck::initPosition()
{
	setPosition(WINDOW_WIDTH /2, WINDOW_HEIGHT /2 );
}

void 	Puck::move(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl;


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
