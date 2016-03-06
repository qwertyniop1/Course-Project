#include "Application.h"

Application::Application()
{
    running = true;
}

int Application::OnExecute()
{
    if (OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while (running) {
        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}
/*
int main(int argc, char* argv[])
{
    Application application;

    return application.OnExecute();
}
*/