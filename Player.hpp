#ifndef PLAYER_H
#define PLAYER_H

#include "Surface.hpp"
#include "defines.hpp"

class Player
{
public:
	Player(char * filename);
	~Player();
	
	virtual void 	initPosition();
	void 	setPosition(int x, int y);
	//std::pair <int,int>& getPosition();
	int getX();
	int getY();
	bool init(SDL_Surface *where);
	SDL_Surface * getSurface();

	private:
		//std::pair <int, int> position;
		int _x;
		int _y;
		SDL_Surface *surface;
		unsigned score;
		char *_filename;
};

#endif