#ifndef PUCK_H
#define PUCK_H

#include "Player.hpp"

class Puck : public Player
{
    public:
    Puck(std:: string const & filename) : Player(filename) {
	xVel = getRandomNum(-2, 2);
    yVel = getRandomNum(-2, 2);
	}
	~Puck() {}
	int getW() const;
	virtual void 	initPosition();
	virtual void 	move(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
	virtual void 	move(Mix_Chunk *chunk);


	int xVel;
	int yVel;

};

#endif // PUCK_H
