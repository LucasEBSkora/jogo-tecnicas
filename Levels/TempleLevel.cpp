#include "TempleLevel.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Entities/Players/ThePenitent.hpp"
// #include "../TileSystem/TileManager.hpp" // Usar tilemanager

namespace DIM {

  TempleLevel::TempleLevel() {
    
  }

  TempleLevel::~TempleLevel() {

  }

  void TempleLevel::init(GraphicsManager* g) {
    Level::init(g);
    // TileManager t;
    // entities.addEntity(&t);
    main_player = new TheUndying();
  }

}