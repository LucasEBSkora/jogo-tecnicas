#include "Level.hpp"

namespace DIM {

  Level::Level(Mob* p1, Mob* p2) : graphics(nullptr), events(nullptr),
    player1(p1), player2(p2), tileManager(nullptr) {
    
  }

  Level::~Level() {

  }

  void Level::init(GraphicsManager& g, EventManager& e) {
    graphics = &g;
    events = &e;
  }

}