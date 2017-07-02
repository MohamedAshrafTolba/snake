/**
 * @file gameSetup.c
 * @brief The file which contains the implementation/definition of the functions responsible
 * for initializing the game and drawing the grid.
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/game.h"
/**
 * A macro for the ANSI escape code which represents the bold red color.
 */
#define ANSI_COLOR_RED "\x1b[1;31m"
/**
 * A macro for the ANSI escape code which represents the regular yellow color.
 */
#define ANSI_COLOR_YELLOW "\x1b[33m"
/**
 * A macro for the ANSI escape code which represents the bold green color.
 */
#define ANSI_COLOR_GREEN "\x1b[1;32m"
/**
 * A macro for the ANSI escape code which represents the regular cyan color.
 */
#define ANSI_COLOR_CYAN "\x1b[36m"
/**
 * A macro for the ANSI escape code which resets the color to the default one.
 */
#define ANSI_COLOR_RESET "\x1b[0m"

void initialize() {
    gameOver = false;
    state = STOP;
    currentSnakeLength = 0;
    currentX = width / 2;
    currentY = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
}
void drawGrid() {
    system("cls");
    printf (ANSI_COLOR_RED"%28sSnake!\n"ANSI_COLOR_RESET,"");
    printf (ANSI_COLOR_CYAN "%23sCurrent Score: %d\n"ANSI_COLOR_RESET,"",score);
    printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET ,218);
    for (int i=0 ; i < width ; i++) {
        printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET ,196);
    }
    printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET ,191);
    printf("\n");
    for (int i=0 ; i < height ; i++) {
        for (int j=0 ; j < width + 2 ; j++) {
            if (j==0 || j == width + 1) {
                printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET ,179);
            } else if (i == currentY && j == currentX) {
                printf("O");
            } else if (i == foodY && j == foodX) {
                printf(ANSI_COLOR_GREEN"$"ANSI_COLOR_RESET);
            } else {
                snakeBodyDetected = false;
                for (int k=0 ; k < currentSnakeLength ; k++) {
                    if (snake[k][0] == j && snake[k][1] == i) {
                        printf("o");
                        snakeBodyDetected = true;
                    }
                }
                if (!snakeBodyDetected) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET ,192);
    for (int i=0 ; i < width ; i++) {
        printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET ,196);
    }
    printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET ,217);
    printf("\n");
}