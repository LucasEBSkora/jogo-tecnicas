#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../GraphicsManager.hpp"

namespace DIM {

  class Entity {

  protected:

    GraphicsManager* manager;

    virtual void initializeSpecific() = 0;

  public: 

    Entity();
    virtual ~Entity();

    virtual void update(float elapsedTime) = 0;
    virtual void draw() const = 0;
    void initializeGeneric(GraphicsManager* Manager);

  };
  
}

#endif