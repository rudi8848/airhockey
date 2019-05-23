#ifndef DEFINES_H
#define DEFINES_H

#include <iostream>

#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define WINDOW_CAPTION  "Air Hockey"

#define STRIKER_WIDTH	90
#define BORDER_WIDTH	10
#define PUCK_WIDTH	65

#include <stdlib.h>
#include <ctime>
#include <SDL_mixer.h>

typedef enum
{
    STATE_NULL,
    MENU,
    PLAY,
    OVER,
    EXIT,
    STATES
} e_state;

int     getRandomNum(int low, int high);
bool    pointInRect(int x, int y, int recX, int recY, int recW);

#endif // DEFINES_H
