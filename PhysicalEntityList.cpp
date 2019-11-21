#include "PhysicalEntityList.hpp"

namespace DIM {

  PhysicalEntityList::PhysicalEntityList() {

  }

  PhysicalEntityList::~PhysicalEntityList() {
    
  }

  void PhysicalEntityList::push(Entities::PhysicalEntity* ent) {
    entities.push_back(ent);
  }

  void PhysicalEntityList::clear() {
    entities.clear();
  }


  void PhysicalEntityList::erase(Entities::PhysicalEntity* ent) {

    for (auto it = entities.begin(); it != entities.end(); ++it) {
      if ((*it) == ent) {
        entities.erase(it);
        break;
      }
    }
  }

  std::deque<Entities::PhysicalEntity*> PhysicalEntityList::asDeque() const {
    
    std::deque<Entities::PhysicalEntity*> deque;
    for (auto& c : entities) {
      deque.push_front(c);
    }

    return deque;
  }

  const std::list<Entities::PhysicalEntity*>& PhysicalEntityList::asStdList() const {
    return entities;
  }
  
}