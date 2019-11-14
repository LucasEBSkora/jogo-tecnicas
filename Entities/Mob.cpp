#include "Mob.hpp"
#include "../Levels/Level.hpp"

namespace DIM {

  Mob::Mob() : vx(0), vy(0), current_level(nullptr) {
    
  }

  Mob::~Mob() {

  }

  void Mob::setPosition(VectorF pos) {
    x = pos.x;
    y = pos.y;
  }

  // VectorF Mob::getPosition() const {
  //   return VectorF(x, y);
  // }

  void Mob::setLevel(Level* level) { // referência?
    current_level = level;
  }

  Level* Mob::getLevel() const {
    return current_level;
  }

}