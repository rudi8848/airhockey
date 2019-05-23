#ifndef PUCK_H
#define PUCK_H

#include "Player.hpp"

class Puck : public Player
{
    public:
    Puck(std:: string const & filename) : Player(filename) {
	xVel = getRandomNum(-10, 10);
    yVel = getRandomNum(-10, 10);
    //std::cerr << xVel << " " << yVel << std::endl;
	}
	~Puck() {}
	virtual void 	initPosition();
	virtual void 	move(SDL_Keycode sym, Uint16 mod, Uint16 scancode);

	//virtual void goLeft();
	//virtual void goRight();

	int xVel;
	int yVel;

};

#endif // PUCK_H
