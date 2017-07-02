#ifndef SNAKE_GAMEDRIVER_H
#define SNAKE_GAMEDRIVER_H

extern bool snakeBodyDetected;
extern bool gameOver;
extern int width,height,currentX, currentY, foodX, foodY, score, currentSnakeLength;
extern int snake[100][2];
enum State {STOP, LEFT, RIGHT, UP, DOWN};
extern enum State state;

#endif //SNAKE_GAMEDRIVER_H
