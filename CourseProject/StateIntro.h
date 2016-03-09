#pragma once

#include "GameState.h"
#include "Texture.h"

class Intro : public GameState
{
protected:
    Intro(GameStateManager *manager) { stateManager = manager; };

private:
    Texture textureLogo;
    byte alpha;

public:
    static Intro* getInstance(GameStateManager *manager)
    {
        static Intro self(manager);
        return &self;
    }

    bool onInit();
    void onEvent(SDL_Event *_event);
    void onLoop();
    void onRender();
    void onCleanup();

    //~Intro();
};


