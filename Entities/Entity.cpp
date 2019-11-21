#include "Entity.hpp"

#include "../Levels/Level.hpp"

namespace DIM {
  namespace Entities {

    Entity::Entity() : position{0.0f, 0.0f}, currentLevel{nullptr} {
      
    }
    
    Entity::~Entity() {

    }

    void Entity::initializeGeneric(Levels::Level* level) {
      
      currentLevel = level;
      initializeSpecific();
    }
    
    void Entity::setLevel(Levels::Level* level) {
      currentLevel = level;
    }

  }
}