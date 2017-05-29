#include "AnimationManager.h"

AnimationManager::~AnimationManager()
{
    //animationsList.clear();
}

void AnimationManager::create(sf::String name, sf::Texture &texture, int x, int y, int width, int height, int count, double speed, int step)
{
    animationsList[name] = Animation(texture, speed);
    currentAnimation = name;
}

void AnimationManager::draw(sf::RenderWindow & window, int x, int y)
{
    animationsList[currentAnimation].sprite.setPosition(x, y);
    window.draw(animationsList[currentAnimation].sprite);
}

void AnimationManager::set(sf::String name)
{
    currentAnimation = name;
}

void AnimationManager::flip(bool flag)
{
    animationsList[currentAnimation].isFlip = flag;
}

void AnimationManager::tick(double time)
{
    animationsList[currentAnimation].tick(time);
}

void AnimationManager::play()
{
    animationsList[currentAnimation].isPlaying = true;
}

void AnimationManager::pause()
{
    animationsList[currentAnimation].isPlaying = false;
}

double AnimationManager::getHeight()
{
    return animationsList[currentAnimation].frames[animationsList[currentAnimation].currentFrame].height;
}

double AnimationManager::getWidth()
{
    return animationsList[currentAnimation].frames[animationsList[currentAnimation].currentFrame].width;
}

bool AnimationManager::loadFromXML(std::string fileName, sf::Texture &texture)
{
    TiXmlDocument animFile(fileName.c_str());

    if (!animFile.LoadFile()) {
        return false;
    }

    TiXmlElement *head;
    head = animFile.FirstChildElement("sprites");

    sf::Image image = texture.copyToImage();
    std::string color = head->Attribute("transparentColor");
    if (color != "") {
        unsigned int colorCode = std::stoi(color, 0, 16);
        sf::Color alphaColor;
        alphaColor.r = colorCode / 0x10000;;  // Extract the RR byte
        alphaColor.g = (colorCode / 0x100) % 0x100;   // Extract the GG byte
        alphaColor.b = colorCode % 0x100;        // Extract the BB byte
        image.createMaskFromColor(sf::Color(alphaColor));
        texture.loadFromImage(image);
    }

    TiXmlElement *animElement;
    animElement = head->FirstChildElement("animation");
    while (animElement)
    {
        currentAnimation = animElement->Attribute("title");
        int delay = atoi(animElement->Attribute("delay"));
        double speed = 1.0 / delay;
        Animation anim(texture, speed);


        TiXmlElement *cut;
        cut = animElement->FirstChildElement("cut");
        while (cut)
        {
            int x = atoi(cut->Attribute("x"));
            int y = atoi(cut->Attribute("y"));
            int w = atoi(cut->Attribute("w"));
            int h = atoi(cut->Attribute("h"));

            anim.frames.push_back(sf::IntRect(x, y, w, h));
            anim.framesFlip.push_back(sf::IntRect(x + w, y, -w, h));
            cut = cut->NextSiblingElement("cut");
        }

        anim.sprite.setOrigin(0, anim.frames[anim.frames.size()-1].height);
        // anim.sprite.setOrigin(0, anim.frames[0].height);

        animationsList[currentAnimation] = anim;
        animElement = animElement->NextSiblingElement("animation");
    }

    return true;
}
