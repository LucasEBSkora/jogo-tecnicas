#include "Screen.h"
#include "Element.h"
#include <iostream>

namespace FISW {

  Screen::Screen(std::vector<Element*> Children) : children{Children} {
    
  }

  Screen::~Screen(){
    for (Element *d : children) {
      delete d;
    }
  }

  int Screen::init(std::map<std::string, sf::Texture*> assets){
    
    //passes the textures to the children
    
    
    int ret = 0;
    for(Element *d : children) {
      if (d->init(assets) == 1) ret = 1; 
    }

    return ret;

  }
      
  void Screen::update(){}

  //just draws each of the children (for now)

  void Screen::draw(sf::RenderWindow *window){

    for(Element *d : children) {
      //d.init(assets);
      d->draw(window);
    }
    
  }

  //gets the list of necessary assets for this screen from the children
  std::list<const char*> Screen::getAssetPathList() const {

      std::list<const char*> paths;

    
    for( Element *d : children) {
      std::list<const char*> screenPaths = d->getAssetPathList();
      paths.insert(paths.end(), screenPaths.begin(), screenPaths.end());  
    }
    
    return paths;
  }

  EventHandlerSettings Screen::getSettings() const {

    EventHandlerSettings sets;

    for( Element *d : children) {
      sets.join(d->getSettings());
    }

    return sets;

  }

}