#ifndef BULLET_HPP
#define BULLET_HPP

#include "Projectile.hpp"

namespace DIM {
  class Bullet : public Projectile {
  private:
  
  public:
    Bullet();
    ~Bullet();

    void update(float elapsedTime) override;
    void draw() const override;
    void initializeSpecific() override;

    void collided(std::string Id, VectorF position, VectorF size) override;
    void adjust() override;

    std::string getID() const override;
  };

}

#endif