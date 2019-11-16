#ifndef BULLET_HPP
#define BULLET_HPP

#include "Projectile.hpp"

namespace DIM {
  class Bullet : public Projectile {
  private:
  
  public:
    Bullet(VectorF position = VectorF(0.0f, 0.0f), VectorF Speed = VectorF(0.0f, 0.0f));
    ~Bullet();

  };

}

#endif