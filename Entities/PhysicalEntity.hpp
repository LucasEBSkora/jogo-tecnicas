#ifndef PHYSICALENTITY_HPP
#define PHYSICALENTITY_HPP

#include "Entity.hpp"

namespace DIM {
  
  class PhysicalEntity : public Entity {
  protected:
    int width;
    int height;
    std::string id; // mais correto talvez seria usar enum
                      // serve para que os objetos identifiquem com quem
                      // colidiram e como devem proceder
  public:
    PhysicalEntity();
    virtual ~PhysicalEntity();

    virtual void collided(std::string Id, VectorF position) = 0;

    VectorF getPos() const;
    VectorF getSize() const;
    virtual std::string getID() const = 0;
  };
}

#endif