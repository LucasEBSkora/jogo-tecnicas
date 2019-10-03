#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <list>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "Element.h"
#include "EventHandlerSettings.h"

namespace FISW {

  class Screen : public Element {
      protected:
      std::vector<FISW::Element*> children;
    
    public:
      Screen(std::vector<FISW::Element*> Children);
      virtual ~Screen();
      
      virtual int init(std::map<std::string, sf::Texture*> assets) override;
      virtual std::list<const char*> getAssetPathList() const override;
      virtual EventHandlerSettings getSettings() const override; 
      virtual void update() override;
      virtual void draw(sf::RenderWindow *window) override;


  };
}

#endif