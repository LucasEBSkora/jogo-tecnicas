#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "Entities/PhysicalEntity.hpp"
#include "Tiles/TileManager.hpp"
#include "../Entities/PhysicalEntityList.hpp"

namespace DIM {
  namespace Managers {

    class CollisionManager {
    private:
      PhysicalEntityList collidables;
      Tiles::TileManager* tile_man;

      bool colliding(Entities::PhysicalEntity* e1, Entities::PhysicalEntity* e2);
    public:
      CollisionManager();
      virtual ~CollisionManager();

      void addToCollisions(Entities::PhysicalEntity* ent);
      void removeFromCollisions(Entities::PhysicalEntity* ent);
      void removeAll();
      void setTileManager(Tiles::TileManager* manager);
      const std::list<Entities::PhysicalEntity*>& getCollidables() const;

      void checkCollisions();
    };

  }
}

#endif