#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>



#include <stdio.h> //temporaly

typedef unsigned char byte;
typedef const char* FILE_PATH;
typedef const char* Text;
typedef unsigned int Time;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGTH = 600;
const char TITLE[] = "SDL Lessons";
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

