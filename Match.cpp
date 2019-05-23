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
            game->enemy->move(sym, mod, scancode);
            game->puck->move(sym, mod, scancode);
            ret = STATE_NULL;
            break;
        }
    }
    return ret;
}

void Match::onLoop()
{

}

void Match::onRender()
{
    Room::onRender();
}

