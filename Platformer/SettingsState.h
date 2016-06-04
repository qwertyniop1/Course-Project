#pragma once

#include "GameState.h"
#include "MenuState.h" 
#include "Interface.h"

//#include <fstream>

class SettingsState : public GameState
{
protected:
    SettingsState(GameStateManager *manager) { 
        stateManager = manager; 
        changeFullscreen = changeResolution = false;
        isFullscreen = false;
    };

public:
    static SettingsState* getInstance(GameStateManager *manager)
    {
        static SettingsState self(manager);
        return &self;
    }

    bool onInit();
    void onEvent(sf::Event event);
    void onLoop();
    void onRender(sf::RenderWindow &window);
    void onCleanup();

private:
    sf::Texture backgroundTexture;
    sf::Sprite background;

    //bool openFile(std::string path);
    sf::Vector2i mouse;
    
    sf::Font font;
    Label textLabel;
    Label languageLabel;
    Label resolutionLabel;
    Label fullscreenLabel;

    Button languageButton;
    Button resolutionButton;
    Button fullscreenButton;

    bool changeResolution, changeFullscreen;
    bool isFullscreen;
    
};