#include "Entity.hpp"

namespace DIM {

  Entity::Entity() : x(0), y(0), manager(nullptr), event_man(nullptr) {
    
  }
  
  Entity::~Entity() {

  }

  void Entity::initializeGeneric(GraphicsManager* Manager, EventManager* events) {
    manager = Manager;
    event_man = events;
    initializeSpecific();
  }
  
}