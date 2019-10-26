#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Element.hpp"
#include "EventHandler.hpp"
#include "EventListeners.hpp"
#include "Model.hpp"

namespace FISW {

class Game {
protected:
  // List of elements which are direct "children" of the game
  std::vector<Element*> elements;

  std::vector<Model*> models;
  // List of every texture which the game will use (needs to be improved to allow any type of file)
  std::map<std::string, sf::Texture*> assets;
  // Which of the elements is currently being processed and show on screen (this class only allows one at a time)
  unsigned long int currentElement;
  bool closeGame;

  sf::RenderWindow* window;

  FISW::EventHandler eventHandler;

  // loads assets, sets up event handler
  int init();

  void gameCloseEvent(sf::Event *e);

public:
  Game(float width, float height, std::string windowTitle, unsigned int style, std::vector<Element*> Elements, std::vector<Model*> Models);
  ~Game();
  int run();
};
} // namespace FISW

#endif