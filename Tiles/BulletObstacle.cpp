#include "BulletObstacle.hpp"

#include "TileManager.hpp"
#include <iostream>
#include "../Levels/Level.hpp"
#include "../Entities/Projectiles/Bullet.hpp"

namespace DIM {
  namespace Tiles {
      
    BulletObstacle::BulletObstacle() : Tile("Wall", "assets/BulletObstacle.png"), delay(0) {


    }
    
    BulletObstacle::~BulletObstacle() {


    }

    void BulletObstacle::collided( const std::string id, const Utils::VectorF positionOther, const Utils::VectorU positionMine) {

      if (id == "Player1") {
        if (delay != 0) {
          --delay;
          return;
        }
        delay = 1000;
        const TileMap *map = parent->getTileMap();
        
        unsigned int i = positionMine.x - 1, j = positionMine.y;
        
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
          if (j < k) searchLeft = false;
          if (j+k > (*map).getSize().x - 1) searchRight = false;

          if (searchLeft) foundLeft = (*map)[i][j-k] == 0; 
          if (searchRight) foundRight = (*map)[i][j+k] == 0;
        }
        --k;

        if (foundLeft) {
          //create arrow at (i, j-k) going right
          Entities::Bullet* bullet = new Entities::Bullet(Utils::VectorF((j - k + 1.5) * size.x, (i + .5) * size.y), Utils::VectorF(100, 0));
          map->getTileManager()->getLevel()->addPhysicalEntity(bullet);

        } else if (foundRight) {
          //create arrow at (i, j+k) going left
          Entities::Bullet* bullet = new Entities::Bullet(Utils::VectorF((j + k - .5) * size.x, (i + .5) * size.y), Utils::VectorF(-100, 0));
          map->getTileManager()->getLevel()->addPhysicalEntity(bullet);

        }

      }
    }

  }
}