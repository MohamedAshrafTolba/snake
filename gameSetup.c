#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "game.h"

void initialize() {
    gameOver = false;
    state = STOP;
    currentX = width / 2;
    currentY = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
}
void drawGrid() {
    system("cls");
    printf ("%28sSnake!\n","");
    printf ("%23sCurrent Score: %d\n","",score);
    printf("%c",218);
    for (int i=1 ; i < width + 1 ; i++) {
        printf("%c",196);
    }
    printf("%c",191);
    printf("\n");
    for (int i=0 ; i < height ; i++) {
        for (int j=0 ; j < width + 2 ; j++) {
            if (j==0 || j == width + 1) {
                printf("%c",179);
            } else if (i == currentY && j == currentX) {
                printf("O");
            } else if (i == foodY && j == foodX) {
                printf("$");
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
    printf("%c",192);
    for (int i=1 ; i < width + 1 ; i++) {
        printf("%c",196);
    }
    printf("%c",217);
    printf("\n");
}