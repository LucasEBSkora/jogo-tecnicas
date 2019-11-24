#include "Mob.hpp"
#include "../Levels/Level.hpp"

namespace DIM {
  namespace Entities {
    namespace Mobs {

      Mob::Mob(const char* path) : PhysicalEntity(path), velocity{0,0} {
        
      }

      Mob::~Mob() {

      }

      void Mob::setPosition(Utils::VectorF pos) {
        position = pos;
      }
    }

  }
}