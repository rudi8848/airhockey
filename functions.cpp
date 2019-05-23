#include "defines.hpp"

int     getRandomNum(int low, int high)
{
    return std::rand() % high + low;
}

bool    pointInRect(int x, int y, int recX, int recY, int recW)
{
    if (x > recX &&
    y > recY &&
    x < recX + recW &&
    y < recY + recW)
        return true;
    return false;
}

bool    pointInRect(int x, int y, int recX, int recY, int recW, int recH)
{
    if (x > recX &&
    y > recY &&
    x < recX + recW &&
    y < recY + recH)
        return true;
    return false;
}
