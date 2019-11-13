#include "Entity.hpp"

namespace DIM {

  Entity::Entity() : x(0), y(0), graphics_manager(nullptr), event_man(nullptr) {
    
  }
  
  Entity::~Entity() {

  }

  void Entity::initializeGeneric(GraphicsManager& g, EventManager& e) {
    graphics_manager = &g;
    event_man = &e;
    initializeSpecific();
  }
  
}