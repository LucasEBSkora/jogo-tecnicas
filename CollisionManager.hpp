#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "Entities/PhysicalEntity.hpp"
#include "TileSystem/TileManager.hpp"

namespace DIM {
  
  class CollisionManager {
  private:
    std::vector<PhysicalEntity*> collidables;
    TileManager* tile_man;
  public:
    CollisionManager();
    virtual ~CollisionManager();
  };
}

#endif