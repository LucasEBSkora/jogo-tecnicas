#include "Entity.hpp"

#include "../Levels/Level.hpp"
#include <iostream>

namespace DIM {
  namespace Entities {

    Entity::Entity(const char* Path) : path{Path}, position{0.0f, 0.0f}, currentLevel{nullptr} {
      
    }
    
    Entity::~Entity() {

    }

    void Entity::draw() const {
        if (currentLevel != nullptr) {
          currentLevel->getGraphicsManager()->draw(path, position);
        } else {
          std::cout << "desenhando objeto nao inicializado\n";
        }
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