#ifndef GAME_H
#define GAME_H

#include "Enemy.hpp"
#include <stdlib.h>
#include <ctime>

class Player;
class Enemy;

class Game
{
    public:
        Game();
        ~Game();

        std::string & getScore();
        void init(SDL_Surface *screen);
        void draw(SDL_Surface *screen);

        Player  *player;
        Enemy   *enemy;
 private:
        std::string scoreStr;
};

#endif // GAME_H
