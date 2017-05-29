#ifndef HIGHSCORES_STATE_H
#define HIGHSCORES_STATE_H

#include "GameState.h"
#include "Interface.h"

struct HighscoreNode {
    std::wstring name;
    size_t score;

    inline bool operator() (const HighscoreNode &first, const HighscoreNode &second) {
        return (first.score > second.score);
    }
};

class HighscoresState : public GameState {
protected:
    HighscoresState(GameStateManager *manager) { stateManager = manager; };

public:
    static HighscoresState* getInstance(GameStateManager *manager) {
        static HighscoresState self(manager);
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
    bool isEmptyList;
    std::vector<HighscoreNode> highscores;
    sf::Font font;
    Label textLabel;
    std::vector<Label*> nodes;

    bool openFile(std::string path);

    std::wstring createNode(std::wstring name, std::wstring score);
};

const unsigned int SIDE_OFFSET = 100;

#endif
