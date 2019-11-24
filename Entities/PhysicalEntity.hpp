#ifndef PHYSICALENTITY_HPP
#define PHYSICALENTITY_HPP

#include "Entity.hpp"
#include <string>
#include "../Utils/GeometricVector.hpp"

namespace DIM {
  namespace Entities {
  
    class PhysicalEntity : public Entity {
    protected:
      int width;
      int height;
      std::string id;
      Utils::VectorF adjusts;
    public:
      PhysicalEntity(const char* Path = nullptr);
      virtual ~PhysicalEntity();

      virtual void collided(std::string Id, Utils::VectorF positionOther, Utils::VectorF size) = 0;
      virtual void adjust();

      Utils::VectorF getPos() const;
      void setPos(Utils::VectorF pos);
      Utils::VectorF getSize() const;
      std::string getID() const;
      Levels::Level* getLevel() const;
    };

  }
}

#endif