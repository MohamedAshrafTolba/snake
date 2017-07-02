/**
 * @file game.h
 * @brief The file which contains the declaration of almost all the global data shared between different source files.
 */
#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
/**
 * A boolean value which indicates whether this row contains a snake body or not.
 */
extern bool snakeBodyDetected;
/**
 * A boolean value which represents the state of the game.
 */
extern bool gameOver;
/**
 * Integers which represent the width and height of the game grid respectively.
 */
extern int width,height;
/**
 * Integers which represent the current-x and current-y of the head of the snake on the game's grid.
 */
extern int currentX, currentY;
/**
 * Integers which represent the current-x and current-y of the food on the game's grid.
 */
extern int foodX, foodY;
/**
 * Integers which represent the current score and current length of snake respectively.
 */
extern int score, currentSnakeLength;
/**
 * Two-dimensional integer array that stores the positions of the snake's body "assuming the maximum length is 100".
 */
extern int snake[100][2];
/**
 * The state enum which represents the state of the snake's movement.
 */
enum State {STOP, LEFT, RIGHT, UP, DOWN};
/**
 * The state enum variable which represents the state of the snake's movement.
 */
extern enum State state;
#endif //SNAKE_GAME_H