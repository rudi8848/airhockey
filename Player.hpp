#ifndef PLAYER_H
#define PLAYER_H

#include "Surface.hpp"
#include "InitError.hpp"
//#include "Event.hpp"
#include "defines.hpp"

class Player
{
public:
	Player(std::string const & filename);
	virtual ~Player();

	virtual void 	initPosition();
	void 	setPosition(int x, int y);

	int getX() const;
	int getY() const;
	int getW() const;
	unsigned  getScore() const;
	void addScore();
	void setX(int x);
	void setY(int y);
	bool init(SDL_Surface *where);
	SDL_Surface * getSurface();
	virtual void move(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
	virtual void goUp();
	virtual void goDown();
	virtual void goLeft();
	virtual void goRight();

	private:
		int _x;
		int _y;
		SDL_Surface *surface;
		unsigned score;
		std::string _filename;
};

#endif
