#include "Game.h"

int FISW::Game::init() {
  int ret = 0;
  
  std::list<const char*> paths;

  //gets the list of necessary assets for every screen, which gets its list from its children
  
  for( FISW::Screen s : screens) {

    std::list<const char*> screenPaths = s.getAssetPathList();
    paths.insert(paths.end(), screenPaths.begin(), screenPaths.end());

  }

  //attempts to load the files into a map which is given to each Drawable on inicialization

  std::cout << "number of assets to load: " << paths.size() << '\n';

  for(const char* s : paths) {
    sf::Texture *tex = new sf::Texture();
    if (!tex->loadFromFile(s)) {
      
      std::cout << "unable to load file at: " << s << '\n'; 
      ret = 1;

    } else {
      std::cout << "file at " << s << " loaded succesfully: " << tex << '\n';
    }

    assets.insert({s, tex});

  }

  std::cout << "assets loaded: " << assets.size() << '\n';
  

  //initializes each screen and its assets
  for( FISW::Screen s : screens) {
    if (s.init(assets) == 1) ret = 1;
  }

  std::cout.flush();
  return ret;


}
    
FISW::Game::Game(std::vector<FISW::Screen> Screens) : screens{Screens}, currentScreen(0), closeGame(false) {
  
}
  


FISW::Game::~Game() {

  //destroys asset list
  for(std::pair<std::string, sf::Texture*> p : assets) {
    delete p.second;

  }

}

int FISW::Game::run() {
  int ret = init();
  std::cout << "init result:" << ret << '\n';

  sf::RenderWindow window(sf::VideoMode(800, 600.0f), "SFML tutorial", sf::Style::Close);
	//sf::RectangleShape player(sf::Vector2f(200.0f, 200.0f));
	
	sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(800.0f, 600.0f));
  
  while (!closeGame) {

    /*   
    window.clear();
    sf::RectangleShape box(sf::Vector2f(100.0f, 100.0f));
    box.setPosition(sf::Vector2f(100.0f,100.0f));
    box.setTexture(assets["bloodboi.png"], true);
    window.draw(box);
    window.display();
    */


    //screens[currentScreen].update();
    
    screens[currentScreen].draw(&window, assets);

  }



  return ret;
  
}