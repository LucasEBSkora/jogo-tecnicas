#include "Projectile.hpp"

namespace DIM {
  
  Projectile::Projectile() {
    
  }
  
  Projectile::~Projectile() {

  }

  void Projectile::setSpeed(VectorF speed) {
    speed_x = speed.x;
    speed_y = speed.y;
  }

}