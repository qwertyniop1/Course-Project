#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H 

#include "GameState.h"
#include "Interface.h"

class SettingsState : public GameState
{
protected:
    SettingsState(GameStateManager *manager) { 
        stateManager = manager; 
        changeFullscreen = changeResolution = false;
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

    sf::Vector2i mouse;
    
    sf::Font font;
    Label textLabel;
    Label languageLabel;
    Label resolutionLabel;
    Label fullscreenLabel;
    Label soundLabel;
    Label musicLabel;

    Button languageButton;
    Button resolutionButton;
    Button fullscreenButton;
    Button soundButton;
    Button musicButton;

    bool changeResolution, changeFullscreen;
    
};

#endif

