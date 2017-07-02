cmake_minimum_required(VERSION 3.7)
project(snake)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES game.c gameSetup.c inputHandler.c gameLogic.c)
set(HEADER_FILES game.h gameSetup.h inputHandler.h gameLogic.h)
add_executable(snake ${SOURCE_FILES})