#include "Application.h"

void Application::onCleanup()
{
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


