#ifndef BULLET_HPP
#define BULLET_HPP

#include "Projectile.hpp"

namespace DIM {
  class Bullet : public Projectile {
  private:
    float delay;
  
  public:
    Bullet(VectorF position = VectorF(0.0f, 0.0f), VectorF Speed = VectorF(0.0f, 0.0f));
    ~Bullet();
    void collided(std::string Id, VectorF position, VectorF size) override;
    void update(float elapsedTime) override;
  };

}

#endif