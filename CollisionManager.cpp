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
    collidables.push_back(ent);
  }

  void CollisionManager::removeFromCollisions(PhysicalEntity* ent) {
    std::vector<PhysicalEntity*>::iterator it = std::find(collidables.begin(),
      collidables.end(), ent);
    if (it != collidables.end()) {
      collidables.erase(it);
    }
  }

  void CollisionManager::setTileManager(TileManager* manager) {
    tile_man = manager;
  }

  void CollisionManager::checkCollisions() {
    std::deque<PhysicalEntity*> deque;
    for (auto& c : collidables) {
      deque.push_front(c);
    }
    while (deque.size() > 0) {
      PhysicalEntity* current = deque.back();
      deque.pop_back();

      if (tile_man) {
        auto vec = tile_man->checkCollisions(current->getPos(), current->getSize(), current->getID());
        for (auto& el : vec) {
          // std::cout << "somebody collided WITH TILES " << el.first << ' ' << el.second.x << ' ' << el.second.y << std::endl;
        }
      } else {
        // std::cout << "no tileman" << std::endl;
      }

      for (auto& c : deque) {
        if (colliding(current, c)) {
          // std::cout << "somebody collided" << std::endl;
        }
      }
    }
  }

}