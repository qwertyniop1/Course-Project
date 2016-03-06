#include "Application.h"

bool Application::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

    }
    return true;
}