#include "PhysicalEntityList.hpp"

namespace DIM {

  PhysicalEntityList::PhysicalEntityList() {

  }

  PhysicalEntityList::~PhysicalEntityList() {
    
  }

  void PhysicalEntityList::push(PhysicalEntity* ent) {
    entities.push_back(ent);
  }

  void PhysicalEntityList::clear() {
    entities.clear();
  }


  void PhysicalEntityList::erase(PhysicalEntity* ent) {

    for (auto it = entities.begin(); it != entities.end(); ++it) {
      if ((*it) == ent) {
        entities.erase(it);
        break;
      }
    }
  }

  std::deque<PhysicalEntity*> PhysicalEntityList::asDeque() const {
    
    std::deque<PhysicalEntity*> deque;
    for (auto& c : entities) {
      deque.push_front(c);
    }

    return deque;
  }

  const std::list<PhysicalEntity*>& PhysicalEntityList::asStdList() const {
    return entities;
  }
}