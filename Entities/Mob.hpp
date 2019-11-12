#ifndef MOB_HPP
#define MOB_HPP

#include "PhysicalEntity.hpp"

namespace DIM {
  class Mob : public PhysicalEntity {
  private:
    int vx;
    int vy;
  public:
    Mob();
    virtual ~Mob();
  };

}

#endif 