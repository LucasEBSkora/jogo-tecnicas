#ifndef MOB_HPP
#define MOB_HPP

#include "PhysicalEntity.hpp"

namespace DIM {
  class Mob : public PhysicalEntity {
  protected:
    float vx;
    float vy;
  public:
    Mob();
    virtual ~Mob();
  };

}

#endif 