#include "Entity.hpp"

#include "../Levels/Level.hpp"

namespace DIM {

  Entity::Entity() : position{0.0f, 0.0f}, currentLevel{nullptr} {
    
  }
  
  Entity::~Entity() {

  }

  void Entity::initializeGeneric(Level* level) {
    
    currentLevel = level;
    initializeSpecific();
  }
  
  void Entity::setLevel(Level* level) {
    currentLevel = level;
  }
}