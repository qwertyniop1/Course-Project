#pragma once

#include "GameState.h"
#include <vector>
#include "Entity.h"

class PlayState : public GameState
{
protected:
    PlayState(GameStateManager *manager) { stateManager = manager; };

private:
    std::vector<Entity*> entityList;
    Entity *player = nullptr;
    
public:
    static PlayState* getInstance(GameStateManager *manager)
    {
        static PlayState self(manager);
        return &self;
    }

    bool onInit();
    void onEvent(SDL_Event *_event);
    void onLoop();
    void onRender();
    void onCleanup();

    void onExit();

    void onKeyDown(SDL_Keycode sym, Uint16 mod);

    
};
