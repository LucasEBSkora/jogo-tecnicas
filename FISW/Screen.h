#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <list>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "Drawable.h"
#include "EventHandlerSettings.h"

namespace FISW {

  class Screen {
      protected:
      std::vector<FISW::Drawable*> children;
    
    public:
      Screen(std::vector<FISW::Drawable*> Children);
      ~Screen();
      
      virtual int init(std::map<std::string, sf::Texture*> assets);
      virtual std::list<const char*> getAssetPathList() const;
      virtual EventHandlerSettings getSettings() const; 

      virtual void update();
      virtual int draw(sf::RenderWindow *window, std::map<std::string, sf::Texture*> assets);


  };
}

#endif