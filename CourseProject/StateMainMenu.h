#pragma once

#include "GameState.h"
#include "Texture.h"

class MainMenu : public GameState
{
protected:
    MainMenu(GameStateManager *manager) { stateManager = manager; };

private:    
    Texture background;

public:
    static MainMenu* getInstance(GameStateManager *manager)
    {
        static MainMenu self(manager);
        return &self;
    }

    bool onInit();
    void onEvent(SDL_Event *_event);
    void onLoop();
    void onRender();
    void onCleanup();

    void onExit();

    void onKeyDown(SDL_Keycode sym, Uint16 mod);

    //~MainMenu();
};