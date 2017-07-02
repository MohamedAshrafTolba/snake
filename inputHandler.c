#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include "game.h"

#define LEFT_KEY 65
#define DOWN_KEY 83
#define RIGHT_KEY 68
#define UP_KEY 87
#define ESC_KEY 27

void handleInput() {
    if (_kbhit()) {
        switch (toupper(_getch())) {
            case LEFT_KEY:
                state = LEFT;
                break;
            case DOWN_KEY:
                state = DOWN;
                break;
            case RIGHT_KEY:
                state = RIGHT;
                break;
            case UP_KEY:
                state = UP;
                break;
            case ESC_KEY:
                gameOver = true;
                break;
        }
    }
}