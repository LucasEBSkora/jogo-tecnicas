#include "Entity.hpp"

#include "../Levels/Level.hpp"

namespace DIM {

  Entity::Entity() : x(0), y(0), currentLevel{nullptr} {
    
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