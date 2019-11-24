#include "CollisionManager.hpp"
#include <algorithm>
#include <deque>
#include <iostream>

namespace DIM {
  namespace Managers {
  
    bool CollisionManager::colliding(Entities::PhysicalEntity* e1, Entities::PhysicalEntity* e2) {
      Utils::VectorF pos1 = e1->getPos();
      Utils::VectorF pos2 = e2->getPos();
      Utils::VectorF size1 = e1->getSize();
      Utils::VectorF size2 = e2->getSize();

      Utils::VectorF c1 = pos1 + size1 * .5;
      Utils::VectorF c2 = pos2 + size2 * .5;

      return (abs(c1.x - c2.x) < (size1.x + size2.x) / 2 &&
              abs(c1.y - c2.y) < (size1.y + size2.y) / 2);
    }

    CollisionManager::CollisionManager() : tile_man(nullptr) {
      
    }

    CollisionManager::~CollisionManager() {

    }


    void CollisionManager::addToCollisions(Entities::PhysicalEntity* ent) {
      collidables.push(ent);
    }

    void CollisionManager::removeFromCollisions(Entities::PhysicalEntity* ent) {
      collidables.erase(ent);
      
    }

    void CollisionManager::removeAll() {
      collidables.clear();
    }

    void CollisionManager::setTileManager(Tiles::TileManager* manager) {
      tile_man = manager;
    }

    const std::list<Entities::PhysicalEntity*>& CollisionManager::getCollidables() const {
      return collidables.asStdList();
    }

    void CollisionManager::checkCollisions() {
      std::deque<Entities::PhysicalEntity*> deque = collidables.asDeque();
      
      while (deque.size() > 0) {
        Entities::PhysicalEntity* current = deque.back();
        deque.pop_back();

        if (tile_man) {
          auto vec = tile_man->checkCollisions(current->getPos(), current->getSize(), current->getID());
          
          for (Tiles::IdPositionSizeTuple& el : vec) {
            current->collided(std::get<0>(el), std::get<1>(el), std::get<2>(el));
          }
        }

        for (auto& c : deque) {
          if (colliding(current, c)) {
            current->collided(c->getID(), c->getPos(), c->getSize());
            c->collided(current->getID(), current->getPos(), current->getSize());
          }
        }
        current->adjust();
      }
    }

  }
}