#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include "inputHandler.h"
#include "gameSetup.h"
#include "game.h"
#include "gameLogic.h"

bool gameOver, snakeBodyDetected;
int width,height,currentX, currentY, foodX, foodY, score, currentSnakeLength;
int snake[100][2];
enum State state;

int main() {
    width = 60;
    height = 20;
    srand(time(NULL));
    initialize();
    while(!gameOver) {
        drawGrid();
        handleInput();
        logic();
        Sleep(30);
    }
    printf("\nGame Over! Your Score: %d\nPress Enter to exit.",score);
    getchar();
}

