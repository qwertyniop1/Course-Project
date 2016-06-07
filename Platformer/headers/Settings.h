#ifndef SETTINGS_H
#define SETTINGS_H 

#include <locale>
#include <codecvt>

#include "Global.h"
#include "TinyXML/tinyxml.h"
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <fstream>

enum Labels {
    START_GAME, HIGHSCORES, SETTINGS, EXIT, BACK, TO_MENU, LANGUAGE, RESOLUTION, FULLSCREEN, GAME_OVER, WIN, LOADING, SOUND, MUSIC
};

enum Sounds {
    COIN, DIE, JUMP, LEVEL_UP, BUMP, GAME_OVER_S
};

enum Music {
    INTRO, MENU, GAME, WINSTATE
};

class Settings {
public:
    Settings();
    ~Settings();

    sf::Vector2i getResolution();
    void changeResolution();
    std::wstring getLabel(Labels label);
    void changeLanguage();
    std::wstring getLanguage();
    void playSound(Sounds sound);
    void playSound(Music music);
    void stopMusic();
    bool isSound();
    bool isMusic();
    bool isFullscreen();
    void switchSound();
    void switchMusic();
    void switchFullscreen();

private:
    std::vector<sf::Vector2i> screenResolutions{ { 800, 600 },{ 1024, 768 },{ 1280, 720 },{1366, 768},{ 1440, 900 },{ 1600, 900 } };
    std::vector<sf::Vector2i>::iterator currentResolution;

    std::unordered_map<std::wstring, std::vector<std::wstring>> labels;
    std::vector<std::wstring> languages;
    std::vector<std::wstring>::iterator currentLanguage;

    std::vector<sf::SoundBuffer*> soundBuffers;
    std::vector<sf::Sound> sounds;
    std::vector<sf::Music*> music;
    sf::Music *playingMusic;

    bool fullscreen, soundEnable, musicEnable;

    const std::string soundPaths[6] = { "res/audio/Coin.wav", "res/audio/Die.wav", "res/audio/jump.wav", "res/audio/win.ogg", "res/audio/bump.wav", "res/audio/game_over.ogg" }; // check
    const std::string musicPaths[2] = { "res/audio/intro.ogg", "res/audio/main.ogg"};
    const std::string SETTING_PATH = "res/conf.dat";

    bool loadSounds();
    bool loadLanguages(std::string filename);
    bool loadSettings(std::string filename);
    bool saveSettings(std::string filename);
#ifdef __linux__
    std::wstring s2ws(const std::string& s);
#endif
};

#endif
