#include "Game.h"

namespace FISW {

int Game::init() {
    int ret = 0;

    std::list<const char*> paths;

    // gets the list of necessary assets for every screen, which gets its list from its children

    for (Element* s : elements) {

        std::list<const char*> screenPaths = s->getAssetPathList();
        paths.insert(paths.end(), screenPaths.begin(), screenPaths.end());
    }

    // attempts to load the files into a map which is given to each Drawable on inicialization

    std::cout << "number of assets to load: " << paths.size() << '\n';

    for (const char* s : paths) {
        sf::Texture* tex = new sf::Texture();
        if (!tex->loadFromFile(s)) {

            std::cout << "unable to load file at: " << s << '\n';
            ret = 1;

        } else {
            std::cout << "file at " << s << " loaded succesfully:\n";
        }

        assets.insert({ s, tex });
    }

    std::cout << "assets loaded: " << assets.size() << '\n';

    // initializes each screen and its assets
    for (Element* s : elements) {
        if (s->init(assets) == 1)
            ret = 1;
    }

    std::cout.flush();
    return ret;
}

Game::Game(float width, float height, std::string windowTitle, unsigned int style, std::vector<Element*> Elements)
    : elements { Elements }
    , currentElement(0)
    , closeGame(false)
    , window { new sf::RenderWindow(sf::VideoMode(width, height), windowTitle, style) } {
}

Game::~Game() {

    // destroys asset list
    for (std::pair<std::string, sf::Texture*> p : assets) {
        delete p.second;
    }

    for (Element* s : elements) {
        delete s;
    }

    delete window;
}

int Game::run() {
    int ret = init();
    std::cout << "init result: " << ret << '\n';

    // sf::RectangleShape player(sf::Vector2f(200.0f, 200.0f));

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));

    EventReport report;

    do {

        report = eventHandler.processEvents(window);

        if (report.errorHappened)
            ret = 1;

        elements[currentElement]->update();

        window->clear();

        elements[currentElement]->draw(window);

        window->display();

    } while (!report.closeGame);

    window->close();

    return ret;
}

void Game::processEvents() {

    sf::Clock clock;

    float deltaTime = 0.0f;
    deltaTime       = clock.restart().asSeconds();

    sf::Event evnt;

    while (window->pollEvent(evnt)) {

        if (evnt.type == sf::Event::Closed) {
            closeGame = true;
        } else if (evnt.type == sf::Event::TextEntered) {
            if (evnt.text.unicode < 128)
                printf("%c", evnt.text.unicode);
        }
    }
}

} // namespace FISW