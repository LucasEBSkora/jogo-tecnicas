#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "../PhysicalEntity.hpp"

namespace DIM {
  class Projectile : public PhysicalEntity {
  protected:
    float speed_x;
    float speed_y;
  public:
    Projectile();
    ~Projectile();

    void setSpeed(VectorF speed);
  };

}

#endif