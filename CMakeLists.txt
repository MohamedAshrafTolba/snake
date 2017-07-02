cmake_minimum_required(VERSION 3.7)
project(snake)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/game.c src/gameSetup.c src/inputHandler.c src/gameLogic.c)
set(HEADER_FILES include/game.h include/gameSetup.h include/inputHandler.h include/gameLogic.h)
add_executable(snake ${SOURCE_FILES})