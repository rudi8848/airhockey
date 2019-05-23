#ifndef ENEMY_H
#define ENEMY_H

#include "Player.hpp"
#include <stdlib.h>


class Enemy : public Player
{
public:
	Enemy(std:: string const & filename) : Player(filename) {
	xVel = getRandomNum(-1, 1);
    yVel = getRandomNum(-1, 1);
    std::cerr << xVel << " " << yVel << std::endl;
	}
	~Enemy() {}
	virtual void 	initPosition();
	virtual void 	move(SDL_Keycode sym, Uint16 mod, Uint16 scancode);

	virtual void goLeft();
	virtual void goRight();

	int xVel;
	int yVel;
};

#endif
