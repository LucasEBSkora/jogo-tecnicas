#include "Enemy.hpp"

#include <iostream>

#include "../../Levels/Level.hpp"

namespace DIM {
  namespace Entities {
    namespace Mobs {

      Enemy::Enemy(const char* path) : Mob(path) {
        
      }

      Enemy::~Enemy() {

      }

      void Enemy::initializeSpecific() {
        currentLevel->getGraphicsManager()->loadAsset(path);
        Utils::VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset(path);
        width = size.x;
        height = size.y;
      }
    }

  }
}