#ifndef ENEMY_H
#define ENEMY_H

#include "Player.hpp"

class Enemy : public Player
{
public:
	Enemy(char *filename) : Player(filename) {}
	~Enemy() {}
	virtual void 	initPosition();
	//virtual void 	move(SDL_Keycode sym, Uint16 mod, Uint16 scancode);

	virtual void goLeft();
	virtual void goRight();
};

#endif