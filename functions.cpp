#include "defines.hpp"

int     getRandomNum(int low, int high)
{
    return std::rand() % high + low;
}
