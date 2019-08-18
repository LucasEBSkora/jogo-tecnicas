#ifndef SCREEN_H
#define SCREEN_H

#include "Drawable.h"
#include <vector>
#include <list>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

namespace FISW {

  class Screen {
      private:
      std::vector<FISW::Drawable> children;
      
    
    public:
      int init(std::map<const char*, sf::Texture*> *assets);
      Screen(const FISW::Drawable *children);
      std::list<const char*> getAssetPathList();
      ~Screen();
      
      void update();
      int draw(sf::RenderWindow *window);


  };
}

#endif