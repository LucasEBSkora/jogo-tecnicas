#include "Entity.hpp"

namespace DIM {

  Entity::Entity() : x(0), y(0), manager(nullptr) {
    
  }
  
  Entity::~Entity() {

  }

  void Entity::initializeGeneric(GraphicsManager* Manager) {
    manager = Manager;
    initializeSpecific();
  }
  
}