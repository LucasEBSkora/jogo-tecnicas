#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "Entities/PhysicalEntity.hpp"
#include "TileSystem/TileManager.hpp"
#include "PhysicalEntityList.hpp"

namespace DIM {
  
  class CollisionManager {
  private:
    PhysicalEntityList collidables;
    TileManager* tile_man;

    bool colliding(PhysicalEntity* e1, PhysicalEntity* e2);
  public:
    CollisionManager();
    virtual ~CollisionManager();

    void addToCollisions(PhysicalEntity* ent);
    void removeFromCollisions(PhysicalEntity* ent);
    void removeAll();
    void setTileManager(TileManager* manager);
    const std::list<PhysicalEntity*>& getCollidables() const;

    void checkCollisions();
  };
}

#endif