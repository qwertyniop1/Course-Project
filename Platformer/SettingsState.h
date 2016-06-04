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
        currentResolution = screenResolutions.begin();
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

    std::vector<sf::Vector2i> screenResolutions{ {800, 600}, {1024, 768}, {1280, 720}, {1400, 1050}, {1600, 900} };
    std::vector<sf::Vector2i>::iterator currentResolution;
    bool changeResolution, changeFullscreen;
    bool isFullscreen;
    
};