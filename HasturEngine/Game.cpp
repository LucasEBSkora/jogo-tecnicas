#include "Game.hpp"

#include <set>

namespace HE {

int Game::init() {
  int ret = 0;

  for (Entity* m : entities) {
    m->init(eventHandler.getListener());
    drawables.insert(drawables.end(), static_cast<Drawable*>(m->generateEntityDrawable()) );

  }

  getAssets();

  // initializes each screen and its assets
  for (Drawable* s : drawables) {
    if (s->init(assets, eventHandler.getListener()) == 1)
      ret = 1;
  }

  // maybe (probably) there is a better way, but it works
  // EventListeners settings;
  // yet another loop
  // for (Drawable* s : drawables) {
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

  for (Drawable* s : drawables) {

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


Game::Game(float width, float height, std::string windowTitle, unsigned int style, std::vector<Drawable*> Drawables, std::vector<Entity*> Entitys)
  : drawables { Drawables }
  , entities {Entitys}
  , currentDrawable(0)
  , closeGame(false)
  , window { new sf::RenderWindow(sf::VideoMode(width, height), windowTitle, style) } {

    window->setKeyRepeatEnabled(false);
}

Game::~Game() {

  // destroys asset list
  for (auto &p : assets) {
    p.second.destroy();
  }

  for (Drawable* s : drawables) {
    delete s;
  }

  for (Entity* m : entities) {
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


} // namespace HE