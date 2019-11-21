#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../GeometricVector.hpp"

namespace DIM {

  class Level;

  class Entity {
  protected:
    
    VectorF position;
    Level* currentLevel;

    virtual void initializeSpecific() = 0;

  public:
    Entity();
    virtual ~Entity();

    virtual void update(float elapsedTime) = 0;
    virtual void draw() const = 0;
    void setLevel(Level* level);
    void initializeGeneric(Level* currentLevel);

  };
  
}

#endif