#pragma once

#include "FISW.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <map>
class FISW::Game {
  private:
    std::vector<Screen> screens;
    std::map<const char*, sf::Texture*> assets;
    int init();
    
  
  public:
    Game(const FISW::Screen *Screens);
    ~Game();
    int run();


};