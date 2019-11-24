#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Utils/GeometricVector.hpp"

namespace DIM {

  namespace Levels {
    class Level;
  }

  namespace Entities {

    class Entity {
    protected:

      const char* path;
      
      Utils::VectorF position;
      Levels::Level* currentLevel;

      virtual void initializeSpecific() = 0;

    public:
      Entity(const char* Path = nullptr);
      virtual ~Entity();

      virtual void update(float elapsedTime) = 0;
      virtual void draw() const;
      void setLevel(Levels::Level* level);
      void initializeGeneric(Levels::Level* currentLevel);

    };
  
  }
}

#endif