#ifndef PHYSICALENTITY_HPP
#define PHYSICALENTITY_HPP

#include "Entity.hpp"

namespace DIM {
  
  class PhysicalEntity : public Entity {
  private:
    int width;
    int height;
    const std::string id; // mais correto talvez seria usar enum
                      // serve para que os objetos identifiquem com quem
                      // colidiram e como devem proceder
  public:
    PhysicalEntity();
    ~PhysicalEntity();

    virtual void collided(std::string Id, VectorF position ) = 0;

    virtual std::string getID() const = 0;
  };
}

#endif