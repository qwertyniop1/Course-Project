#include "HighscoresState.h"
#include "MenuState.h" 

bool HighscoresState::onInit()
{
    LOAD_TEXTURE(backgroundTexture.loadFromFile("res/background.jpg"));

    setAndScale(background, backgroundTexture, stateManager->settings.getResolution().x, stateManager->settings.getResolution().y);

    LOAD_FONT(font.loadFromFile("res/comic.ttf"));

    isEmptyList = openFile("res/scores.dat");

    std::sort(highscores.begin(), highscores.end(), HighscoreNode());
    for (size_t i = 0; (i < highscores.size()) && (i < 5); ++i) {
        nodes.push_back(new Label());
        nodes[i]->create(createNode(highscores[i].name, std::to_wstring(highscores[i].score)), font, SIDE_OFFSET, i * 50 + 200);
    }
    for (size_t i = highscores.size(); i < 5; ++i) {
        nodes.push_back(new Label());
        nodes[i]->create(createNode(L"Noname", L"0"), font, SIDE_OFFSET, i * 50 + 200);
    }

    textLabel.create(stateManager->settings.getLabel(Labels::HIGHSCORES), font);
    textLabel.setPosition((stateManager->settings.getResolution().x - textLabel.getBounds().width) / 2, 100);
    
    return true;
}

void HighscoresState::onEvent(sf::Event event)
{
   if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) {
            TRY_CHANGE_STATE(MenuState::getInstance(stateManager));
        }
    }
}

void HighscoresState::onLoop()
{
    
}

void HighscoresState::onRender(sf::RenderWindow & window)
{
    window.setView(window.getDefaultView());
    window.draw(background);

    window.draw(textLabel.displayText());
    for (auto label : nodes) {
        window.draw(label->displayText());
    }
}

void HighscoresState::onCleanup() 
{
    for (auto label : nodes) {
        delete label;
    }
    nodes.clear();
    highscores.clear();

    background.setPosition(0, 0);
    textLabel.create(L"", font);

}

bool HighscoresState::openFile(std::string path)
{
    std::wifstream inputFile;
    inputFile.open(path, std::ios::in);
    if (!inputFile.is_open() || inputFile.eof()) { //check
        return false;
    }

    while (!inputFile.eof()) {
        HighscoreNode node;
        std::getline(inputFile, node.name);
        if (inputFile.eof()) {
            break;
        }
        inputFile >> node.score;
        inputFile.ignore(10, '\n');
        highscores.push_back(node);
    }

    inputFile.close();

    return true;
}

std::wstring HighscoresState::createNode(std::wstring name, std::wstring score)
{
    std::wstring result;

    Label tmp;
    size_t width = 0;
    tmp.create(name, font);
    width += tmp.getBounds().width;
    tmp.create(score, font);
    width += tmp.getBounds().width;

    result = name;
    result.push_back(' ');

    for (size_t i = 0; i < stateManager->settings.getResolution().x - SIDE_OFFSET * 2 - width; i += 15) {
        result.push_back('.');
    }

    result.push_back(' ');
    result += score;

    return result;
}
