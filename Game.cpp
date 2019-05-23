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
void Game::checkCollisions()
{
    int plX = player->getX();
    int plY = player->getY();

    int pX = puck->getX();
    int pY = puck->getY();

    int eX = enemy->getX();
    int eY = enemy->getY();


    //---   puck with player
     if ((pY >= plY && pY <= plY + STRIKER_WIDTH &&
     pX >= plX && pX <= plX + STRIKER_WIDTH))
     {
        std::cerr << "COLLISION!!!" << std::endl;
     }
     else if (pY + PUCK_WIDTH >= plY && pY + PUCK_WIDTH < plY + STRIKER_WIDTH
     && pX + PUCK_WIDTH >= plX && pX + PUCK_WIDTH <= plX + STRIKER_WIDTH)
     {
        std::cerr << "COLLISION!!!" << std::endl;
     }
    /*
    if ((pY >= plY && pY < plY + STRIKER_WIDTH &&
    pX >= oX && pX <= oX + STRIKER_WIDTH) ||
    (pY + PUCK_WIDTH >= oY && pY + PUCK_WIDTH < oY + STRIKER_WIDTH &&
    pX + PUCK_WIDTH >= oX && pX + PUCK_WIDTH <= oX + STRIKER_WIDTH) )
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

int Game::timer = 0;
