#include "Bullet.hpp"

namespace DIM {

  Bullet::Bullet(VectorF position, VectorF speed) : Projectile(position, speed, "assets/Bullet.png"), delay{0.2f}  { 
    id = "Bullet";
  }
  
  Bullet::~Bullet(){ 

  }

  void Bullet::collided(std::string Id, VectorF position, VectorF size) {
    if (Id == "Player1" || Id == "Player2")
      Projectile::collided(Id, position, size);
    else if (delay <= 0) 
      Projectile::collided(Id, position, size);
  }

  void Bullet::update(float elapsedTime) {
    Projectile::update(elapsedTime);
    if (delay > 0) delay -= elapsedTime;
  }

}