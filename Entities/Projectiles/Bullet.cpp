#include "Bullet.hpp"

namespace DIM {

  Bullet::Bullet(VectorF position, VectorF speed) : Projectile(position, speed, "assets/Bullet.png")  { 

  }
  
  Bullet::~Bullet(){ 

  }

}