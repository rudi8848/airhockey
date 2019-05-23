#include "Match.hpp"

Match::Match(SDL_Surface* scr, int rwidth, int rheight) : Room(scr, rwidth, rheight)
{
    this->text = "Score: ";
    this->text_x = 140;
    this->text_y = 20;
    this->r = 255;
    this->g = 0;
    this->b = 0;

    game = new Game();
    text += game->getScore();
    game->init(getScreen());

}

Match::~Match()
{

}

int Match::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    int ret = STATE_NULL;

    switch(sym)
    {
        case SDLK_ESCAPE:
        {
            ret = EXIT;
            break;
        }
        /*
        case SDLK_SPACE:
        {
            ret = PLAY;
            break;
        }
        */
        default:
        {
            game->player->move(sym, mod, scancode);

            ret = STATE_NULL;
            break;
        }
    }
    return ret;
}

int     Match::onUser(Uint8 type, int code, void *data1, void *data2)
{
std::cerr << __PRETTY_FUNCTION__ << std::endl;

    return STATE_NULL;
}

void Match::onLoop()
{
    uint32_t timer = SDL_GetTicks();

    if ( timer % 3 == 0)
    {
            game->enemy->move(0, 0, 0);
            game->puck->move(0, 0, 0);
        if (game->checkCollision(game->puck, game->player) == true)
        {
            game->puck->xVel = - game->puck->xVel;
        }
        if (game->checkCollision(game->puck, game->enemy) == true)
        {
            game->puck->xVel = - game->puck->xVel;
    }
    }
}

void Match::onRender()
{

    Room::onRender();
}

