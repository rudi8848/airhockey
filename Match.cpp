#include "Match.hpp"

Match::Match(SDL_Surface* scr, int rwidth, int rheight) : Room(scr, rwidth, rheight)
{

    this->text = "Use arrows to move!";
    this->text_x = 140;
    this->text_y = 20;
    this->r = 255;
    this->g = 0;
    this->b = 0;

    game = new Game();
    game->init(getScreen());

    hit1 = Mix_LoadWAV("Sounds/AirHockey_MalletHitPuck01.wav");
    hit2 = Mix_LoadWAV("Sounds/AirHockey_MalletHitPuck03.wav");
    hit3 = Mix_LoadWAV("Sounds/AirHockey_PuckHitSide02.wav");
    goal = Mix_LoadWAV("Sounds/AirHockey_GoalScore01.wav");

if (!hit1 || !hit2 || !hit3 || !goal)
    throw InitError("Music load error!");
}

Match::~Match()
{
    if (game)
    {
        delete game;
        game = nullptr;
    }
    if (hit1)
    {
        Mix_FreeChunk(hit1);
        hit1 = nullptr;
    }
    if (hit2)
    {
        Mix_FreeChunk(hit2);
        hit2 = nullptr;
    }
    if (hit3)
    {
        Mix_FreeChunk(hit3);
        hit3 = nullptr;
    }
    if (goal)
    {
        Mix_FreeChunk(goal);
        goal = nullptr;
    }
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
        default:
        {
            if(game)
                game->player->move(sym, mod, scancode);

            ret = STATE_NULL;
            break;
        }
    }
    return ret;
}

void Match::onLoop()
{
    uint32_t ticks = SDL_GetTicks();

    if (!game)
        return;
    if ( ticks % 3 == 0)
    {
        if (game->timer)
        {
            --game->timer;
        }
        else
        {
            /*      with player    */
            if (game->checkHCollision(game->puck, game->player) == true)
            {
                Mix_PlayChannel(-1, hit1, 0);
                game->puck->xVel = - game->puck->xVel;
                game->puck->move(hit3);
            }
            else if (game->checkVCollision(game->puck, game->player) == true)
            {
                Mix_PlayChannel(-1, hit1, 0);
                game->puck->yVel = - game->puck->yVel;
                game->puck->move(hit3);
            }
            else if (game->checkDCollision(game->puck, game->player) == true)
            {
                Mix_PlayChannel(-1, hit1, 0);
                game->puck->xVel = - game->puck->xVel;
                game->puck->yVel = - game->puck->yVel;
                game->puck->move(hit3);
            }
            /*      with enemy    */
            if (game->checkHCollision(game->puck, game->enemy) == true)
            {
                Mix_PlayChannel(-1, hit2, 0);
                game->puck->xVel = - game->puck->xVel;
                game->puck->move(hit3);
            }
            else if (game->checkVCollision(game->puck, game->enemy) == true)
            {
                Mix_PlayChannel(-1, hit2, 0);
                game->puck->yVel = - game->puck->yVel;
                game->puck->move(hit3);
            }
            else if (game->checkDCollision(game->puck, game->enemy) == true)
            {
                Mix_PlayChannel(-1, hit2, 0);
                game->puck->xVel = - game->puck->xVel;
                game->puck->yVel = - game->puck->yVel;
                game->puck->move(hit3);
            }
            game->enemy->move(0, 0, 0);
            game->puck->move(hit3);

            if (game->inPlayerGate())
            {
                Mix_PlayChannel(-1, goal, 0);
                game->enemy->addScore();
                game->puck->init(getScreen());
                this->text = "Score: " + game->getScore();
                game->timer = 50;
            }
            else if (game->inEnemyGate())
            {
                Mix_PlayChannel(-1, goal, 0);
                game->player->addScore();
                game->puck->init(getScreen());
                this->text = "Score: " + game->getScore();
                game->timer = 50;
            }
            if (game->isOver())
            {
                if (game->player->getScore() < game->enemy->getScore())
                    this->text = "Fail ... Esc to exit";
                else
                    this->text = "Victory!  Esc to exit";

                delete game;
                game = nullptr;

            }
        }
    }
}

void Match::onRender()
{
    Room::onRender();
}


