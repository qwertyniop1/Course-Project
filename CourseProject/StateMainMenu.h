#pragma once

#include "GameState.h"

class MainMenu : public GameState
{
protected:
    MainMenu();

private:
    static MainMenu self;

public:
    static MainMenu* getInstance()
    {
        return &self;
    }

    bool onInit();
    void onEvent(SDL_Event *_event);
    void onLoop();
    void onRender();
    void onCleanup();

    ~MainMenu();
};