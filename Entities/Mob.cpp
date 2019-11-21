#include "Mob.hpp"
#include "../Levels/Level.hpp"

namespace DIM {
  namespace Entities {

    Mob::Mob() : PhysicalEntity(), velocity{0,0} {
      
    }

    Mob::~Mob() {

    }

    void Mob::setPosition(Utility::VectorF pos) {
      position = pos;
    }

  }
}