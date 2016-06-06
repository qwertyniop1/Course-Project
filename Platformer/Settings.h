#pragma once

#include <locale>
#include <codecvt>

#include "Global.h"
#include "TinyXML\tinyxml.h"
#include <SFML\Audio.hpp>
#include <unordered_map>

enum Labels;
enum Sounds;
enum Music;

class Settings {
public:
    Settings();

    sf::Vector2i getResolution();
    void changeResolution();
    std::wstring getLabel(Labels label);
    bool loadLanguages(std::string filename);
    void changeLanguage();
    std::wstring getLanguage();
    void playSound(Sounds sound);
    void playSound(Music music);
    void stopMusic();

private:
    std::vector<sf::Vector2i> screenResolutions{ { 800, 600 },{ 1024, 768 },{ 1280, 720 },{ 1400, 1050 },{ 1600, 900 } };
    std::vector<sf::Vector2i>::iterator currentResolution;

    std::unordered_map<std::wstring, std::vector<std::wstring>> labels;
    std::vector<std::wstring> languages;
    std::vector<std::wstring>::iterator currentLanguage;

    std::vector<sf::SoundBuffer*> soundBuffers;
    std::vector<sf::Sound> sounds;
    std::vector<sf::Music*> music;
    sf::Music *playingMusic;

    const std::string soundPaths[4] = { "res/audio/Coin.wav", "res/audio/Die.wav", "res/audio/jump.wav", "res/audio/win.ogg" }; // check
    const std::string musicPaths[2] = { "res/audio/intro.ogg", "res/audio/main.ogg"};

    bool loadSounds();

};

enum Labels {
    START_GAME, HIGHSCORES, SETTINGS, EXIT, BACK, TO_MENU, LANGUAGE, RESOLUTION, FULLSCREEN, GAME_OVER, WIN, LOADING
};

enum Sounds {
    COIN, DIE, JUMP, LEVEL_UP
};

enum Music {
    INTRO, MENU, GAME, WINSTATE, LOSE
};