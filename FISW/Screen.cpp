#include "Screen.h"
#include "Drawable.h"
#include <iostream>

namespace FISW {

  int Screen::init(std::map<std::string, sf::Texture*> assets){
    
    //passes the textures to the children
    
    
    int ret = 0;
    for(Drawable *d : children) {
      if (d->init(assets) == 1) ret = 1; 
    }

    return ret;

  }



  Screen::Screen(std::vector<Drawable*> Children) : children{Children} {
    
  }

  //gets the list of necessary assets for this screen from the children
  std::list<const char*> Screen::getAssetPathList() const {

      std::list<const char*> paths;

    
    for( Drawable *d : children) {
      std::list<const char*> screenPaths = d->getAssetPathList();
      paths.insert(paths.end(), screenPaths.begin(), screenPaths.end());  
    }
    
    return paths;
  }

  Screen::~Screen(){
    for (Drawable *d : children) {
      delete d;
    }
  }
      
  void Screen::update(){}

  //just draws each of the children (for now)

  int Screen::draw(sf::RenderWindow *window, std::map<std::string, sf::Texture*> assets){
      window->clear();

    for(Drawable *d : children) {
      //d.init(assets);
      d->draw(window);
    }
    
      window->display();
    return 0;
  }

}