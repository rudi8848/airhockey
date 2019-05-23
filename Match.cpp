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

    hit1 = Mix_LoadWAV("Sounds/AirHockey_MalletHitPuck01.wav");
    hit2 = Mix_LoadWAV("Sounds/AirHockey_MalletHitPuck03.wav");
    hit3 = Mix_LoadWAV("Sounds/AirHockey_PuckHitSide02.wav");
    goal = Mix_LoadWAV("Sounds/AirHockey_GoalScore01.wav");

if (!hit1 || !hit2 || !hit3 || !goal)
    throw InitError("Music load error!");
}

Match::~Match()
{
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
     if (game->checkHCollision(game->puck, game->player) == true)
        {
            Mix_PlayChannel(-1, hit1, 0);
            game->puck->xVel = - game->puck->xVel;
            game->puck->move(0, 0, 0);
        }
        if (game->checkHCollision(game->puck, game->enemy) == true)
        {
            Mix_PlayChannel(-1, hit2, 0);
            game->puck->xVel = - game->puck->xVel;
            game->puck->move(0, 0, 0);
        }
        game->enemy->move(0, 0, 0);
        game->puck->move(0, 0, 0);

    }
}

void Match::onRender()
{

    Room::onRender();
}

