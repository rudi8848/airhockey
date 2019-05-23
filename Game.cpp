#include "Game.hpp"

Game::Game()
{
std::cerr << __PRETTY_FUNCTION__<< std::endl;
    player = new Player("Backgrounds/player1.bmp");
    enemy = new Enemy("Backgrounds/player2.bmp");
    puck = new Puck("Backgrounds/puck.bmp");
    srand(time(NULL));
    scoreStr = "0 - 0";
}

Game::~Game()
{

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
bool Game::checkCollision(Player *p1, Player *p2)
{
    if (pointInRect(p1->getX(), p1->getY(), p2->getX(), p2->getY(), p2->getW()) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY(), p2->getX(), p2->getY(), p2->getW()) == true ||
    pointInRect(p1->getX(), p1->getY() + p1->getW(), p2->getX(), p2->getY(), p2->getW()) == true ||
    pointInRect(p1->getX() + p1->getW(), p1->getY() + p1->getW(), p2->getX(), p2->getY(), p2->getW()) == true)
    {
        std::cerr << "COLLISION!!!!" << std::endl;
        return true;
    }
    return false;

/*
    int plX = player->getX();
    int plY = player->getY();

    int pX = puck->getX();
    int pY = puck->getY();

    int eX = enemy->getX();
    int eY = enemy->getY();
*/


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

