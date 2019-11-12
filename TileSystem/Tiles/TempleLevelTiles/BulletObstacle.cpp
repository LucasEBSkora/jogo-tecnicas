#include "BulletObstacle.hpp"

namespace DIM {
  BulletObstacle::BulletObstacle() : Tile("Wall", "assets/BulletObstacle.png") {


  }
  
  BulletObstacle::~BulletObstacle() {


  }

  void BulletObstacle::collided(std::string id, VectorF positionOther, VectorU positionMine) {
    
    //todo: criar bala

  }
}