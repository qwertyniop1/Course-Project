#pragma once

#include "GameState.h"
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "LevelManager.h"

class PlayState : public GameState
{
protected:
    PlayState(GameStateManager *manager) { stateManager = manager; };

private:
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    LevelManager levelManager; //tmp
    Enemy *enemy;
    
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

    //void onKeyDown(SDL_Keycode sym, Uint16 mod);
   // void onKeyUp(SDL_Keycode sym, Uint16 mod);

    
};
