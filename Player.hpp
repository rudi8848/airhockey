#ifndef PLAYER_H
#define PLAYER_H

#include "Surface.hpp"
//#include "Event.hpp"
#include "defines.hpp"

class Player
{
public:
	Player(std::string const & filename);
	~Player();

	virtual void 	initPosition();
	void 	setPosition(int x, int y);
	//std::pair <int,int>& getPosition();
	int getX() const;
	int getY() const;
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
		//std::pair <int, int> position;
		int _x;
		int _y;
		SDL_Surface *surface;
		unsigned score;
		std::string _filename;
};

#endif
