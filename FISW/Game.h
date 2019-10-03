#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>

#include "Element.h"
#include "EventHandler.h"
#include "EventHandlerSettings.h"
#include "EventReport.h"

namespace FISW {

  class Game {
    protected:

      //List of elements which are direct "children" of the game
      std::vector<FISW::Element*> elements;
      //List of every texture which the game will use (needs to be improved to allow any type of file)
      std::map<std::string, sf::Texture*> assets;
      //Which of the elements is currently being processed and show on screen (this class only allows one at a time)
      long unsigned int currentElement;
      bool closeGame;

      sf::RenderWindow* window;

      FISW::EventHandler eventHandler;

      //loads assets, sets up event handler
      int init();
      //calls event handler (needs to be redone)
      void processEvents();
    
    public:
      Game(float width, float height, std::string windowTitle, unsigned int style, std::vector<Element*> Elements);
      ~Game();
      int run();
      
  };
}

#endif