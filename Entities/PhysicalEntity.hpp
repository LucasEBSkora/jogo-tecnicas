#ifndef PHYSICALENTITY_HPP
#define PHYSICALENTITY_HPP

#include "Entity.hpp"
#include <string>
#include "../GeometricVector.hpp"

namespace DIM {
  namespace Entities {
  
    class PhysicalEntity : public Entity {
    protected:
      int width;
      int height;
      std::string id;
      Utility::VectorF adjusts;
    public:
      PhysicalEntity();
      virtual ~PhysicalEntity();

      virtual void collided(std::string Id, Utility::VectorF positionOther, Utility::VectorF size) = 0;
      virtual void adjust();

      Utility::VectorF getPos() const;
      void setPos(Utility::VectorF pos);
      Utility::VectorF getSize() const;
      std::string getID() const;
      Levels::Level* getLevel() const;
    };

  }
}

#endif