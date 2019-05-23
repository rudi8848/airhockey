#include "Game.hpp"

Game::Game()
{
std::cerr << __PRETTY_FUNCTION__<< std::endl;
    player = new Player("Backgrounds/player1.bmp");
    enemy = new Enemy("Backgrounds/player2.bmp");
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
}

void    Game::draw(SDL_Surface *screen)
{
    std::cerr << __PRETTY_FUNCTION__<< std::endl;
    Surface::drawSurface(player->getSurface(), screen, player->getX(), player->getY());
    Surface::drawSurface(enemy->getSurface(), screen, enemy->getX(), enemy->getY());

}


