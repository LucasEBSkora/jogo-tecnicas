#include "Level.hpp"

namespace DIM {

  Level::Level() : graphics(nullptr), main_player(nullptr) {
    
  }

  Level::~Level() {

  }

  void Level::init(GraphicsManager* g) { // talvez mudar pra parâmetro por referência
    graphics = g;
    events.setGraphicsManager(graphics);
  }

}