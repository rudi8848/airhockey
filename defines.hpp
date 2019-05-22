#ifndef DEFINES_H
#define DEFINES_H

#include <iostream>

#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define WINDOW_CAPTION  "Air Hockey"

#define STRIKER_WIDTH	96
#define BORDER_WIDTH	10

typedef enum
{
    STATE_NULL,
    MENU,
    PLAY,
    PAUSED,
    EXIT,
    STATES
} e_state;

#endif // DEFINES_H
