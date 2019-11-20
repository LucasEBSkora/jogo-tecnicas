#include "CollisionManager.hpp"
#include <algorithm>
#include <deque>
#include <iostream>

namespace DIM {
  
  bool CollisionManager::colliding(PhysicalEntity* e1, PhysicalEntity* e2) {
    VectorF pos1 = e1->getPos();
    VectorF pos2 = e2->getPos();
    VectorF size1 = e1->getSize();
    VectorF size2 = e2->getSize();

    VectorF c1 = pos1 + size1 * .5;
    VectorF c2 = pos2 + size2 * .5;

    return (abs(c1.x - c2.x) < (size1.x + size2.x) / 2 &&
            abs(c1.y - c2.y) < (size1.y + size2.y) / 2);
  }

  CollisionManager::CollisionManager() : tile_man(nullptr) {
    
  }

  CollisionManager::~CollisionManager() {

  }


  void CollisionManager::addToCollisions(PhysicalEntity* ent) {
    collidables.push(ent);
  }

  void CollisionManager::removeFromCollisions(PhysicalEntity* ent) {
    collidables.erase(ent);
    
  }

  void CollisionManager::removeAll() {
    collidables.clear();
  }

  void CollisionManager::setTileManager(TileManager* manager) {
    tile_man = manager;
  }

  const std::list<PhysicalEntity*>& CollisionManager::getCollidables() const {
    return collidables.asStdList();
  }

  void CollisionManager::checkCollisions() {
    std::deque<PhysicalEntity*> deque = collidables.asDeque();
    
    while (deque.size() > 0) {
      PhysicalEntity* current = deque.back();
      deque.pop_back();

      if (tile_man) {
        auto vec = tile_man->checkCollisions(current->getPos(), current->getSize(), current->getID());
        
        for (IdPositionSizeTuple& el : vec) {
          current->collided(std::get<0>(el), std::get<1>(el), std::get<2>(el));
          // std::apply(current->collided, el);
          // std::cout << current->getID() <<  " collided with a tile of type \"" << std::get<0>(el) << "\" at "  << ' ' << std::get<1>(el).x << ' ' << std::get<1>(el).y << std::endl;
        }
      } else {
        // std::cout << "no tileman" << std::endl;
      }

      for (auto& c : deque) {
        if (colliding(current, c)) {
          current->collided(c->getID(), c->getPos(), c->getSize());
          c->collided(current->getID(), current->getPos(), current->getSize());
          // std::cout << current->getID() << " collided with " << c->getID() << std::endl;
        }
      }
      current->adjust();
    }
  }

}