#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Drawable.hpp"
#include "EventHandler.hpp"
#include "EventListeners.hpp"
#include "Entity.hpp"
#include "Asset.hpp"

namespace HE {

class Game {
protected:
  
  std::vector<Drawable*> drawables;

  std::vector<Entity*> entities;
  
  // List of every texture which the game will use (needs to be improved to allow any type of file)
  std::map<std::string, Asset> assets;
  // Which of the elements is currently being processed and show on screen (this class only allows one at a time)
  unsigned long int currentDrawable;
  bool closeGame;

  sf::RenderWindow* window;

  HE::EventHandler eventHandler;

  // loads assets, sets up event handler
  int init();
  int getAssets(); 

  void gameCloseEvent(sf::Event *e);

public:
  Game(float width, float height, std::string windowTitle, unsigned int style, std::vector<Drawable*> Elements, std::vector<Entity*> Entities = std::vector<Entity*>());
  ~Game();
  int run();
};
} // namespace HE

#endif