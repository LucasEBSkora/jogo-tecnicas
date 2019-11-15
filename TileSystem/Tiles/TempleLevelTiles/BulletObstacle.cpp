#include "BulletObstacle.hpp"

#include "../../TileManager.hpp"
#include <iostream>
#include "../../../Levels/Level.hpp"
#include "../../../Entities/Projectiles/Bullet.hpp"

namespace DIM {
  BulletObstacle::BulletObstacle() : Tile("Wall", "assets/BulletObstacle.png"), delay(0) {


  }
  
  BulletObstacle::~BulletObstacle() {


  }

  void BulletObstacle::collided( const std::string id, const VectorF positionOther, const VectorU positionMine) {

    if (id == "Player1") {
      if (delay != 0) {
        --delay;
        return;
      }
      delay = 1000;
      const TileMap *map = parent->getTileMap();
      
      unsigned int i = positionMine.x - 1, j = positionMine.y;
      std::cout << i << ',' << j << std::endl;
      bool searchLeft, searchRight;

      try {
      
        searchLeft = (*map)[i][j-1] != 0;
      
      } catch (std::string s) {
      
        searchLeft = false;
      
      }
      
      try {

       searchRight = (*map)[i][j+1] != 0;

      } catch (std::string s) {
        
        searchRight = false;
      
      }
      
      bool foundLeft = false, foundRight = false;
      unsigned int k;
      for (k = 2; (searchLeft || searchRight) && (!foundLeft && !foundRight); ++k) {
        if (j-k < 0) searchLeft = false;
        if (j+k > (*map).getSize().x - 1) searchRight = false;

        if (searchLeft) foundLeft = (*map)[i][j-k] == 0; 
        if (searchRight) foundRight = (*map)[i][j+k] == 0;
      }

      if (foundLeft) {
        std::cout << "criando flecha indo para a direita em " << (j + 0.5)*size.x << ',' << (i + 0.5)*size.y  << std::endl;
        //create arrow at (i, j-k) going right
        Bullet* bullet = new Bullet();
        bullet->setSpeed(VectorF(100, 0));
        bullet->setPos(VectorF((j - k - 1.5) * size.x, (i + .5) * size.y));
        map->getTileManager()->getCurrentLevel()->addPhysicalEntity(bullet);

      } else if (foundRight) {
        //create arrow at (i, j+k) going left
        std::cout << "criando flecha indo para a esquerda em " << (j + 0.5)*size.x << ',' << (i + 0.5)*size.y  << std::endl;
        Bullet* bullet = new Bullet();
        bullet->setSpeed(VectorF(-100, 0));
        bullet->setPos(VectorF((j + k - 1.5) * size.x, (i + .5) * size.y));
        map->getTileManager()->getCurrentLevel()->addPhysicalEntity(bullet);

      }

    }
  }

}