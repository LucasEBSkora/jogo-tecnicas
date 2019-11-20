#ifndef PHYSICALENTITY_HPP
#define PHYSICALENTITY_HPP

#include "Entity.hpp"
#include <string>
#include "../Vector.hpp"

namespace DIM {
  
  class PhysicalEntity : public Entity {
  protected:
    int width;
    int height;
    std::string id; // mais correto talvez seria usar enum
                      // serve para que os objetos identifiquem com quem
                      // colidiram e como devem proceder
    VectorF adjusts;
  public:
    PhysicalEntity();
    virtual ~PhysicalEntity();

    virtual void collided(std::string Id, VectorF positionOther, VectorF size) = 0;
    virtual void adjust();

    VectorF getPos() const;
    void setPos(VectorF pos);
    VectorF getSize() const;
    virtual std::string getID() const;
    Level* getLevel() const;
  };
}

#endif