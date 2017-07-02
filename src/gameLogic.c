/**
 * @file gameLogic.c
 * @brief The file contains the implementation/definition of the function responsible
 * for logic of the snake's movements and checks for the game over condition.
 */
#include <stdlib.h>
#include <stdbool.h>
#include "../include/game.h"

void logic() {
    int previousX = snake[0][0];
    int previousY = snake[0][1];
    int nextPreviousX, nextPreviousY;
    snake[0][0] = currentX;
    snake[0][1] = currentY;
    for (int i = 1 ; i < currentSnakeLength ; i++) {
        nextPreviousX = snake[i][0];
        nextPreviousY = snake[i][1];
        snake[i][0] = previousX;
        snake[i][1] = previousY;
        previousX = nextPreviousX;
        previousY = nextPreviousY;
    }
    switch (state) {
        case LEFT:
            currentX--;
            break;
        case DOWN:
            currentY++;
            break;
        case RIGHT:
            currentX++;
            break;
        case UP:
            currentY--;
            break;
    }

    if (currentX >= width) {
        currentX = 0;
    } else if (currentX < 0) {
        currentX = width - 1;
    }

    if (currentY >= height) {
        currentY = 0;
    } else if (currentY < 0) {
        currentY = height - 1;
    }

    for (int i=0 ; i < currentSnakeLength ; i++) {
        if (currentX == snake[i][0] && currentY == snake[i][1]) {
            gameOver = true;
        }
    }
    if (currentX == foodX && currentY == foodY) {
        score += 5;
        snake[currentSnakeLength][0] = foodX;
        snake[currentSnakeLength][1] = foodY;
        foodX = rand() % width;
        foodY = rand() % height;
        currentSnakeLength++;
    }
}