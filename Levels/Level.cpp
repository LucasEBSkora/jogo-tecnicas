#include "Level.hpp"
#include <iostream>

namespace DIM {

  Level::Level() : graphics(nullptr), events(nullptr), player1(nullptr),
    player2(nullptr), tileManager(nullptr) {
    
  }

  Level::~Level() {

  }

  void Level::init(GraphicsManager& g, EventManager& e) {
    graphics = &g;
    events = &e;
  }

  VectorF Level::getPlayer1Center() const {
    if (player1 == nullptr) std::cout << "segfaulting agora" << std::endl;
    return player1->getPos() + player1->getSize() * .5;
  }
}