#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"

namespace DIM {

  class Entity {
  protected:
    float x;
    float y;
    GraphicsManager* manager;
    EventManager* event_man;

    virtual void initializeSpecific() = 0;

  public:
    Entity();
    virtual ~Entity();

    virtual void update(float elapsedTime) = 0;
    virtual void draw() const = 0;
    void initializeGeneric(GraphicsManager* Manager, EventManager* event);

  };
  
}

#endif