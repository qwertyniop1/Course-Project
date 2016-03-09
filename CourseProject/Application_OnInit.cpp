#include "Application.h"

bool Application::onInit()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error SDL initialization. %s", SDL_GetError());
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("Error IMG initialization. %s", IMG_GetError());
        return false;
    }

    if (TTF_Init() != 0) {
        printf("Error TTF initialization. %s", TTF_GetError());
        return false;
    }

    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGTH, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Error. Couldn't create window. %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        printf("Error. Couldn't create renderer. %s", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}