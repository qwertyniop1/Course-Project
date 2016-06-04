#include "Settings.h"

Settings::Settings()
{
    currentResolution = screenResolutions.begin();
    
    loadLanguages("res/lang.xml");
    currentLanguage = languages.begin();

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
