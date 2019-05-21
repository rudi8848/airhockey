#include "Enemy.hpp"

void 	Enemy::initPosition()
{
	setPosition(WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH, WINDOW_HEIGHT /2 - STRIKER_WIDTH / 2);
}
/*
void 	Enemy::move(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{

}
*/
void Enemy::goLeft()
{
	//if (this->_x > BORDER_WIDTH)
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
	//if (this->_x < WINDOW_WIDTH / 2 - BORDER_WIDTH - STRIKER_WIDTH)
	int x = this->getX();
	if (x < WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH)
    {
    	this->setX(x +10);
    	if (this->getX() > WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH)
    		this->setX(WINDOW_WIDTH - BORDER_WIDTH - STRIKER_WIDTH);
    }
}