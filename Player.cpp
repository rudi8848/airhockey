#include "Player.hpp"

Player::Player(char * filename)
{
	_filename = filename;
}

Player::~Player()
{
	SDL_FreeSurface(surface);
    surface = nullptr;
}

bool Player::init(SDL_Surface *where)
{
	surface = Surface::loadSurface(_filename,where);	// null check at App::onInit
	if (!surface)
	{
		std::cerr << "Player init error: " << SDL_GetError() << std::endl;
		return false;
	}
	initPosition();
	score = 0;
	return true;
}

void Player::initPosition()
{
	setPosition(BORDER_WIDTH, WINDOW_HEIGHT / 2 - STRIKER_WIDTH / 2);
}

int Player::getX() const
{
	return _x;
}

int Player::getY() const
{
	return _y;
}

void Player::setX(int x)
{
	_x = x;
}

void Player::setY(int y)
{
	_y = y;
}

void Player::setPosition(int x, int y)
{
	setX(x);
	setY(y);
}

SDL_Surface * Player::getSurface()
{
	return surface;
}

void Player::goUp()
{
	if (this->_y > BORDER_WIDTH)
    {
     	this->_y -= 10;
        if (this->_y < BORDER_WIDTH)
        	this->_y = BORDER_WIDTH;
	}
}

void Player::goDown()
{
	if (this->_y < WINDOW_HEIGHT - BORDER_WIDTH - STRIKER_WIDTH)
    {
        this->_y += 10;
        if (this->_y > WINDOW_HEIGHT - BORDER_WIDTH - STRIKER_WIDTH)
        	this->_y = WINDOW_HEIGHT - BORDER_WIDTH - STRIKER_WIDTH;
    }
}

void Player::goLeft()
{
    if (this->_x > BORDER_WIDTH)
    {
        this->_x -= 10;
        if (this->_x < BORDER_WIDTH)
        	this->_x = BORDER_WIDTH;
    }
}

void Player::goRight()
{

    if (this->_x < WINDOW_WIDTH / 2 - BORDER_WIDTH - STRIKER_WIDTH)
    {
    	this->_x += 10;
    	if (this->_x > WINDOW_WIDTH / 2  - STRIKER_WIDTH)
    		this->_x = WINDOW_WIDTH / 2  - STRIKER_WIDTH;
    }
}

void Player::move(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
	switch(sym)
    {
        
        case SDLK_UP:
        {
        	goUp();
        	break;
        }
        case SDLK_DOWN:
        {
        	goDown();
        	break;
        }
        case SDLK_LEFT:
        {
        	goLeft();        	
        	break;
        }
        case SDLK_RIGHT:
        {
        	goRight();
        	break;
        }
    }
}