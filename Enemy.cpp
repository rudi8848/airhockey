#include "Enemy.hpp"

void 	Enemy::initPosition()
{
	setPosition(WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH, WINDOW_HEIGHT /2 - STRIKER_WIDTH / 2);
}

void 	Enemy::move(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl;


    int x = getX();
    int y = getY();

    x += xVel;
    y += yVel;

    if (x < WINDOW_WIDTH / 2 )
    {
       xVel = -xVel;
       x = WINDOW_WIDTH / 2;
    }
    else if (x > WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH)
    {
        x = WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH;
        xVel = -xVel;
    }
    if (y < BORDER_WIDTH)
    {
        yVel = -yVel;
        y = BORDER_WIDTH;
    }
    else if (y > WINDOW_HEIGHT - BORDER_WIDTH - STRIKER_WIDTH)
    {
        y =  WINDOW_HEIGHT - BORDER_WIDTH - STRIKER_WIDTH;
        yVel = -yVel;
    }
    setPosition(x, y);
}

void Enemy::goLeft()
{
	int x = this->getX();
	if (x > WINDOW_WIDTH / 2 )
    {
        this->setX(x - 10);
        if (this->getX() < WINDOW_WIDTH / 2 )
        	this->setX(WINDOW_WIDTH / 2 );
    }
}

void Enemy::goRight()
{
	int x = this->getX();
	if (x < WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH)
    {
    	this->setX(x +10);
    	if (this->getX() > WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH)
    		this->setX(WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH);
    }
}
