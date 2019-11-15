#include "BulletObstacle.hpp"

#include "../../TileManager.hpp"

namespace DIM {
  BulletObstacle::BulletObstacle() : Tile("Wall", "assets/BulletObstacle.png") {


  }
  
  BulletObstacle::~BulletObstacle() {


  }

  void BulletObstacle::collided(std::string id, VectorF positionOther, VectorU positionMine) {
    
    if (id == "Player1") {
      TileMap map = parent->getTileMap();
      
      unsigned int i = positionMine.y - 1, j = positionMine.x;

      try {
        if (map[i][j-1] == 0) {
          //procurar para a direita
        }

      } catch (std::string s) {

      }

      

    }

  }
}