#include "Entity.hpp"

namespace DIM {
  
  Entity::~Entity() {

  }

  void Entity::initializeGeneric(GraphicsManager* Manager) {
    manager = Manager;
    initializeSpecific();
  }
  
}