#ifndef GAME_H
#define GAME_H

#include "Screen.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <list>

namespace FISW {

  class Game {
    protected:

      std::vector<FISW::Screen*> screens;
      std::map<std::string, sf::Texture*> assets;
      long unsigned int currentScreen;
      bool closeGame;
      sf::RenderWindow* window;

      int init();
      void processEvents();
    
    public:
      Game(std::vector<FISW::Screen*> Screens);
      ~Game();
      int run();
      

  };
}

#endif