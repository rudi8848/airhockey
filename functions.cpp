#include "defines.hpp"

int     getRandomNum(int low, int high)
{
    return std::rand() % high + low;
}
/*
bool    checkLeft(int oX, int oY, int pX, int pY)
{
    //  up left

    if ((pY >= oY && pY < oY + STRIKER_WIDTH &&
    pX >= oX && pX <= oX + STRIKER_WIDTH) ||
    (pY + PUCK_WIDTH >= oY && pY + PUCK_WIDTH < oY + STRIKER_WIDTH &&
    pX + PUCK_WIDTH >= oX && pX + PUCK_WIDTH <= oX + STRIKER_WIDTH) )
    {
        std::cerr << "COLLISION!!!" << std::endl;
        return true;
    }
    return false;
}
*/
