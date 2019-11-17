#include "Mob.hpp"
#include "../Levels/Level.hpp"

namespace DIM {

  Mob::Mob() : PhysicalEntity(), velocity{0,0} {
    
  }

  Mob::~Mob() {

  }

  void Mob::setPosition(VectorF pos) {
    position = pos;
  }

  // VectorF Mob::getPosition() const {
  //   return VectorF(x, y);
  // }


  Level* Mob::getLevel() const {
    return currentLevel;
  }

}