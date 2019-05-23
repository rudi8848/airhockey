#ifndef GAME_H
#define GAME_H

#include "Enemy.hpp"
#include "Puck.hpp"
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

        bool checkCollision(Player *p1, Player *p2);
        bool isOver();

        Player  *player;
        Enemy   *enemy;
        Puck    *puck;

 private:
        std::string scoreStr;
};

#endif // GAME_H
