#include "Settings.h"

Settings::Settings()
{
    currentResolution = screenResolutions.begin();
    
    loadLanguages("res/lang.xml");
    currentLanguage = languages.begin();

    loadSounds();

    playingMusic = nullptr;

    soundEnable = musicEnable = true;
    fullscreen = false;

    loadSettings(SETTING_PATH);
}

Settings::~Settings()
{
    saveSettings(SETTING_PATH);
}

sf::Vector2i Settings::getResolution()
{
    return { (*currentResolution).x, (*currentResolution).y};
}

void Settings::changeResolution()
{
    currentResolution++;
    if (currentResolution == screenResolutions.end()) {
        currentResolution = screenResolutions.begin();
    }
}

std::wstring Settings::getLabel(Labels label)
{
    return labels[*currentLanguage].at(label);
}

bool Settings::loadLanguages(std::string filename)
{
    TiXmlDocument animFile(filename.c_str());

    if (!animFile.LoadFile()) {
        return false;
    }

    TiXmlElement *head;
    head = animFile.FirstChildElement("languages");

    TiXmlElement *languageElement;
    languageElement = head->FirstChildElement("language");

    std::wstring currentLanguage;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    while (languageElement)
    {
        currentLanguage = converter.from_bytes(languageElement->Attribute("name"));
        std::vector<std::wstring> currentLabels;

        TiXmlElement *label;
        label = languageElement->FirstChildElement("label");
        while (label)
        {
            currentLabels.push_back(converter.from_bytes(label->GetText()));
            
            label = label->NextSiblingElement("label");
        }

        labels[currentLanguage] = currentLabels;
        languages.push_back(currentLanguage);

        languageElement = languageElement->NextSiblingElement("language");
    }

    return true;
}

bool Settings::loadSettings(std::string filename)
{
    std::ifstream file;
    file.open(filename, std::ios::in);
    if (!file.is_open() || file.eof()) {
        return false;
    }

    size_t value;

    file >> value;
    file.ignore(10, '\n');
    currentResolution = screenResolutions.begin() + value;
    file >> value;
    file.ignore(10, '\n');
    fullscreen = (bool)value;
    file >> value;
    file.ignore(10, '\n');
    currentLanguage = languages.begin() + value;
    file >> value;
    file.ignore(10, '\n');
    soundEnable = (bool)value;
    file >> value;
    file.ignore(10, '\n');
    musicEnable = (bool)value;

    file.close();
    
    return true;
}

bool Settings::saveSettings(std::string filename)
{
    std::ofstream file;
    file.open(filename, std::ios::out);

    file << currentResolution - screenResolutions.begin() << std::endl;
    file << (size_t)fullscreen << std::endl;
    file << currentLanguage - languages.begin() << std::endl;
    file << (size_t)soundEnable << std::endl;
    file << (size_t)musicEnable << std::endl;

    file.close();
    
    return true;
}

void Settings::changeLanguage()
{
    currentLanguage++;
    if (currentLanguage == languages.end()) {
        currentLanguage = languages.begin();
    }
}

std::wstring Settings::getLanguage()
{
    return *currentLanguage;
}

void Settings::playSound(Sounds sound)
{
    if (soundEnable)
        sounds.at(sound).play();
}

void Settings::playSound(Music music)
{
    if (!musicEnable) //
        return;
    sf::Music *oldMusic = playingMusic;
    playingMusic = this->music.at(music);
        
    if (playingMusic == oldMusic)
        return;

    if (oldMusic) {
        oldMusic->stop();
    }

    playingMusic->play();

}

void Settings::stopMusic()
{
    if (playingMusic != nullptr) {
        playingMusic->stop();
        playingMusic = nullptr;
    }
}

bool Settings::isSound()
{
    return soundEnable;
}

bool Settings::isMusic()
{
    return musicEnable;
}

bool Settings::isFullscreen()
{
    return fullscreen;
}

void Settings::switchSound()
{
    soundEnable = !soundEnable;
}

void Settings::switchMusic()
{
    musicEnable = !musicEnable;
}

void Settings::switchFullscreen()
{
    fullscreen = !fullscreen;
}

bool Settings::loadSounds()
{
    for each (std::string file in soundPaths) {
        sf::SoundBuffer *buffer = new sf::SoundBuffer();
        buffer->loadFromFile(file);
        soundBuffers.push_back(buffer);
        sf::Sound sound;
        sound.setBuffer(*buffer);
        sounds.push_back(sound);
    }

    for each (std::string file in musicPaths) {
        sf::Music *currentMusic = new sf::Music();
        currentMusic->openFromFile(file);
        music.push_back(currentMusic);
    }

    return true;
}
