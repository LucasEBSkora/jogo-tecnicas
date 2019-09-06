#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "EventHandler.h"
#include "EventHandlerSettings.h"
#include "EventReport.h"

namespace FISW {

  class Game {
    protected:

      std::vector<FISW::Screen*> screens;
      std::map<std::string, sf::Texture*> assets;
      long unsigned int currentScreen;
      bool closeGame;
      sf::RenderWindow* window;
      FISW::EventHandler eventHandler;
      
      int init();
      void processEvents();
    
    public:
      Game(std::vector<FISW::Screen*> Screens);
      ~Game();
      int run();
      

  };
}

#endif