#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../GeometricVector.hpp"

namespace DIM {

  namespace Levels {
    class Level;
  }

  namespace Entities {

    class Entity {
    protected:
      
      Utils::VectorF position;
      Levels::Level* currentLevel;

      virtual void initializeSpecific() = 0;

    public:
      Entity();
      virtual ~Entity();

      virtual void update(float elapsedTime) = 0;
      virtual void draw() const = 0;
      void setLevel(Levels::Level* level);
      void initializeGeneric(Levels::Level* currentLevel);

    };
  
  }
}

#endif