#include "Mob.hpp"

namespace DIM {

  Mob::Mob() : vx(0), vy(0) {
    
  }

  Mob::~Mob() {

  }

  void Mob::setPosition(VectorF pos) {
    x = pos.x;
    y = pos.y;
  }

  VectorF Mob::getPosition() const {
    return VectorF(x, y);
  }
}