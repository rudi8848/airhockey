#include "Game.hpp"

Game::Game()
{
    player = new Player("Backgrounds/player1.bmp");
    //player = new Player("Backgrounds/player1.png");
    enemy = new Enemy("Backgrounds/player2.bmp");
    //enemy = new Enemy("Backgrounds/player2.png");
    puck = new Puck("Backgrounds/puck.bmp");
    //puck = new Puck("Backgrounds/puck.png");
    srand(time(NULL));
    timer = 1;
    scoreStr = "0 - 0";
}

Game::~Game()
{
    if (player)
    {
        delete player;
        player = nullptr;
    }
    if (enemy)
    {
        delete enemy;
        enemy = nullptr;
    }
    if (puck)
    {
        delete puck;
        puck = nullptr;
    }
}

std::string & Game::getScore()
{
    scoreStr = std::to_string(player->getScore()) + " - " + std::to_string(enemy->getScore());
    return scoreStr;
}

void    Game::init(SDL_Surface *screen)
{
    player->init(screen);
    enemy->init(screen);
    puck->init(screen);
}

void    Game::draw(SDL_Surface *screen)
{

}
bool Game::checkHCollision(Player *p1, Player *p2)
{
    /*
            *  *  *
            x  *  X
            *  *  *
    */
    int p2x = p2->getX();
    int p2w = p2->getW() / 3;
    int p2y = p2->getY() + p2w;


    if (pointInRect(p1->getX(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true)
    {
        return true;
    }
    p2x += 2*p2w;
     if (pointInRect(p1->getX(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true)
    {
        return true;
    }

    return false;
}

bool Game::checkVCollision(Player *p1, Player *p2)
{
    /*
            *  X  *
            *  *  *
            *  X  *
    */
    int p2w = p2->getW() / 3;
    int p2x = p2->getX() + p2w;
    int p2y = p2->getY();
     if (pointInRect(p1->getX(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true)
    {
        return true;
    }
    p2y += 2*p2w;
    if (pointInRect(p1->getX(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true)
    {
        return true;
    }

    return false;
}

bool Game::checkDCollision(Player *p1, Player *p2)
{
    /*
            x  *  x
            *  *  *
            x  *  x
    */
    int p2w = p2->getW() / 3;
    int p2x = p2->getX();
    int p2y = p2->getY();
    if (pointInRect(p1->getX(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true)
    {
        return true;
    }
    p2x += 2 * p2w;
    if (pointInRect(p1->getX(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true)
    {
        return true;
    }
    p2y += 2 * p2w;
    if (pointInRect(p1->getX(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true)
    {
        return true;
    }
    p2x = p2->getX();
    if (pointInRect(p1->getX(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2x, p2y, p2w) == true)
    {
        return true;
    }

    return false;
}

bool Game::inPlayerGate()
{
    int p2x = 0;
    int p2y = 180;
    int p2w = 80;
    int p2h = 100;

    if (pointInRect(puck->getX(), puck->getY(), p2x, p2y, p2w, p2h) == true ||
    pointInRect(puck->getX() + puck->getW(), puck->getY(), p2x, p2y, p2w, p2h) == true ||
    pointInRect(puck->getX(), puck->getY() + puck->getW(), p2x, p2y, p2w, p2h) == true ||
    pointInRect(puck->getX() + puck->getW(), puck->getY() + puck->getW(), p2x, p2y, p2w, p2h) == true)
    {
        return true;
    }
    return false;
}

bool Game::inEnemyGate()
{
    int p2x = WINDOW_WIDTH - 90;
    int p2y = 180;
    int p2w = 80;
    int p2h = 100;

    if (pointInRect(puck->getX(), puck->getY(), p2x, p2y, p2w, p2h) == true ||
    pointInRect(puck->getX() + puck->getW(), puck->getY(), p2x, p2y, p2w, p2h) == true ||
    pointInRect(puck->getX(), puck->getY() + puck->getW(), p2x, p2y, p2w, p2h) == true ||
    pointInRect(puck->getX() + puck->getW(), puck->getY() + puck->getW(), p2x, p2y, p2w, p2h) == true)
    {
        return true;
    }
    return false;
}

bool Game::isOver()
{
    if (player->getScore() == 7)
    {
        return true;
    }
    if (enemy->getScore() == 7)
    {
        return true;
    }
    return false;
}

