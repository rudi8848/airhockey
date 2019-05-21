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
	setPosition(BORDER_WIDTH, BORDER_WIDTH);
}

int Player::getX()
{
	return _x;
}

int Player::getY()
{
	return _y;
}

void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

SDL_Surface * Player::getSurface()
{
	return surface;
}