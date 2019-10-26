#include "Game.hpp"

#include <set>

namespace FISW {

int Game::init() {
  int ret = 0;

  for (Model* m : models) {
    m->init(eventHandler.getListener());
    elements.insert(elements.end(), static_cast<Element*>(m->generateModelDrawer()) );

  }

  getAssets();

  // initializes each screen and its assets
  for (Element* s : elements) {
    if (s->init(assets, eventHandler.getListener()) == 1)
      ret = 1;
  }

  // maybe (probably) there is a better way, but it works
  // EventListeners settings;
  // yet another loop
  // for (Element* s : elements) {
  //   settings.join(s->getSettings());
  // }

  eventHandler.getListener()->subscribe("system", [this](sf::Event* e){ gameCloseEvent(e); });

  // eventHandler.updateListeners(settings);

  std::cout.flush();
  return ret;
}

int Game::getAssets() {
  int ret = 0;


  std::set<const char*> paths;

  // gets the list of necessary assets for every element

  for (Element* s : elements) {

    std::set<const char*> screenPaths = s->getAssetPathList();
    paths.insert(screenPaths.begin(), screenPaths.end());

  }

  // attempts to load the files into a map which is given to each Drawable on inicialization

  std::cout << "number of assets to load: " << paths.size() << '\n';

  for (const char* s : paths) {
    

    Asset asset;
     
    if (!asset.load(s)) {

      std::cout << "unable to load file at: " << s << '\n';
      ret = 1;

    } else {
      std::cout << "file at " << s << " loaded succesfully:\n";
    }

    assets.insert({ s, asset});
  }

  std::cout << "assets loaded: " << assets.size() << '\n';

  return ret;
}


Game::Game(float width, float height, std::string windowTitle, unsigned int style, std::vector<Element*> Elements, std::vector<Model*> Models)
  : elements { Elements }
  , models {Models}
  , currentElement(0)
  , closeGame(false)
  , window { new sf::RenderWindow(sf::VideoMode(width, height), windowTitle, style) } {

    window->setKeyRepeatEnabled(false);
}

Game::~Game() {

  // destroys asset list
  for (auto &p : assets) {
    p.second.destroy();
  }

  for (Element* s : elements) {
    delete s;
  }

  for (Model* m : models) {
    delete m;
  }

  delete window;
}

int Game::run() {
  int ret = init();
  std::cout << "init result: " << ret << '\n';

  // sf::RectangleShape player(sf::Vector2f(200.0f, 200.0f));

  sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));

  eventHandler.resetTime();

  do {

    if (!eventHandler.processEvents(window))
      ret = 1;

  } while (!closeGame);

  window->close();

  return ret;
}

void Game::gameCloseEvent(sf::Event *e) {
  if (e->type == sf::Event::Closed) {
    std::cout << "close button pressed!" << std::endl;
    closeGame = true;
  }
}


} // namespace FISW