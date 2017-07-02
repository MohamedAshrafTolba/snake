/**
 * @file inputHandler.c
 * @brief The file which contains the implementation/definition of the function responsible
 * for handling user's input.
 */
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include "../include/game.h"
/**
 * A macro for the ASCII code which represents the 'A' key.
 */
#define LEFT_KEY 65
/**
 * A macro for the ASCII code which represents the 'S' key.
 */
#define DOWN_KEY 83
/**
 * A macro for the ASCII code which represents the 'D' key.
 */
#define RIGHT_KEY 68
/**
 * A macro for the ASCII code which represents the 'W' key.
 */
#define UP_KEY 87
/**
 * A macro for the ASCII code which represents the 'Esc' key.
 */
#define ESC_KEY 27

void handleInput() {
    if (kbhit()) {
        switch (toupper(getch())) {
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