/**
 * @file game.c
 * @brief The file which contains the main logic of the game.
 */
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "../include/game.h"
#include "../include/gameSetup.h"
#include "../include/inputHandler.h"
#include "../include/gameLogic.h"
/**
 * A macro for the ANSI escape code which represents the regular red color.
 */
#define ANSI_COLOR_RED "\x1b[31m"
/**
 * A macro for the ANSI escape code which represents the regular cyan color.
 */
#define ANSI_COLOR_CYAN "\x1b[36m"
/**
 * A macro for the ANSI escape code which resets the color to the default one.
 */
#define ANSI_COLOR_RESET "\x1b[0m"

bool gameOver, snakeBodyDetected;
int width,height,currentX, currentY,foodX, foodY,score, currentSnakeLength;
int snake[100][2];
enum State state;

/**
 * A function which controls the main logic of the game and initializes the grid's
 * width and height as well as the seed of the random number generator.
 * @return 0 - indicating normal termination else abnormal abortion to the program.
 */
int main() {
    srand(time(NULL));
    width = 60;
    height = 20;
    while(true) {
        system("cls");
        initialize();
        while(!gameOver) {
            drawGrid();
            handleInput();
            logic();
            Sleep(25);
        }
        printf(ANSI_COLOR_RED"\nGame Over!"ANSI_COLOR_CYAN" Your Score: %d\n"
                       ANSI_COLOR_RED"Press (N) for new game anything else will exit the game."ANSI_COLOR_RESET,score);
        if (toupper(getch()) != 'N') {
            break;
        }
    }
    return 0;
}