#pragma once

#include <locale>
#include <codecvt>

#include "Global.h"
#include "TinyXML\tinyxml.h"

enum Labels;

class Settings {
public:
    Settings();

    sf::Vector2i getResolution();
    void changeResolution();
    std::wstring getLabel(Labels label);
    bool loadLanguages(std::string filename);
    void changeLanguage();
    std::wstring getLanguage();

private:
    std::vector<sf::Vector2i> screenResolutions{ { 800, 600 },{ 1024, 768 },{ 1280, 720 },{ 1400, 1050 },{ 1600, 900 } };
    std::vector<sf::Vector2i>::iterator currentResolution;

    std::map<std::wstring, std::vector<std::wstring>> labels;
    std::vector<std::wstring> languages;
    std::vector<std::wstring>::iterator currentLanguage;
};

enum Labels {
    START_GAME, HIGHSCORES, SETTINGS, EXIT, BACK, TO_MENU, LANGUAGE, RESOLUTION, FULLSCREEN, GAME_OVER
};