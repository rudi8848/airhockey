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

        bool checkHCollision(Player *p1, Player *p2);
        bool checkVCollision(Player *p1, Player *p2);
        bool checkDCollision(Player *p1, Player *p2);
        bool inPlayerGate();
        bool inEnemyGate();
        bool isOver();

        Player  *player;
        Enemy   *enemy;
        Puck    *puck;

        int     timer;

 private:
        std::string scoreStr;
};

#endif // GAME_H
