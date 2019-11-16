#include "Mob.hpp"
#include "../Levels/Level.hpp"

namespace DIM {

  Mob::Mob() : PhysicalEntity(), vx(0), vy(0) {
    
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


  Level* Mob::getLevel() const {
    return currentLevel;
  }

}