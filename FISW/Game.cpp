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

  for(const char* s : paths) {
    sf::Texture *tex = new sf::Texture();
    if (!tex->loadFromFile(s)) {
      
      std::cout << "unable to load file: " << s << std::endl; 
      ret = 1;

    } 

    assets.insert({s, tex});

  }

  //initializes each screen and its assets
  for( FISW::Screen s : screens) {
    s.init(&assets);
  }

  return ret;


}
    
FISW::Game::Game(FISW::Screen Screens[]) : currentScreen(0), closeGame(false) {

  int n = sizeof(Screens)/sizeof(Screens[0]);

  screens = std::vector<FISW::Screen>(Screens, Screens + n);

}
  


FISW::Game::~Game() {

  //destroys asset list
  for(std::pair<const char *, sf::Texture*> p : assets) {
    delete p.second;

  }

}

int FISW::Game::run() {
  int ret = init();

  sf::RenderWindow window(sf::VideoMode(800, 600.0f), "SFML tutorial", sf::Style::Close);
	//sf::RectangleShape player(sf::Vector2f(200.0f, 200.0f));
	
	sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(800.0f, 600.0f));
  
  while (!closeGame) {

    screens[currentScreen].update();
    
    screens[currentScreen].draw(&window);

  }



  return ret;
  
}