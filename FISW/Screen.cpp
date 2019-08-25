#include "Screen.h"
#include "Drawable.h"
#include <iostream>

int FISW::Screen::init(std::map<std::string, sf::Texture*> assets){
  
  //passes the textures to the children
  
  
  int ret = 0;
  for(FISW::Drawable d : children) {
    if (d.init(assets) == 1) ret = 1; 
  }

  return ret;

}



FISW::Screen::Screen(std::vector<FISW::Drawable> Children) : children{Children} {

}

//gets the list of necessary assets for this screen from the children
std::list<const char*> FISW::Screen::getAssetPathList(){

    std::list<const char*> paths;

  
  for( FISW::Drawable d : children) {
    std::list<const char*> screenPaths = d.getAssetPathList();
    paths.insert(paths.end(), screenPaths.begin(), screenPaths.end());  
  }
  
  return paths;
}

FISW::Screen::~Screen(){}
    
void FISW::Screen::update(){}

//just draws each of the children (for now)

int FISW::Screen::draw(sf::RenderWindow *window, std::map<std::string, sf::Texture*> assets){
    window->clear();

  for(FISW::Drawable d : children) {
    //d.init(assets);
    d.draw(window);
  }
  
    window->display();
  return 0;
}