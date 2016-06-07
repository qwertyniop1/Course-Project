#ifndef LEVEL_H
#define LEVEL_H 

#include "TinyXML/tinyxml.h"

#include <string>
#include <vector>
#include <map>
#include "Global.h"

struct Object {
    int getPropertyInt(std::string name);
    double getPropertyFloat(std::string name);
    std::string getPropertyString(std::string name);

    std::string name;
    std::string type;
    sf::Rect<float> rect;
    std::map<std::string, std::string> properties;
    sf::Sprite sprite;
};

struct Layer {
    int opacity;
    std::vector<sf::Sprite> tiles;
};

class Level {
public:
    bool loadFromFile(std::string filename);
    Object getObject(std::string name);
    std::vector<Object> getObjects(std::string name);
    std::vector<Object> getAllObjects();
    void draw(sf::RenderWindow &window);
    sf::Vector2i getTileSize();

private:
    int width, height, tileWidth, tileHeight;
    int firstTileID;
    sf::Rect<double> drawingBounds;
    sf::Texture tilesetImage;
    std::vector<Object> objects;
    std::vector<Layer> layers;
};

#endif
