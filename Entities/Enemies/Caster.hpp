#ifndef CASTER_HPP
#define CASTER_HPP

#include "Enemy.hpp"

namespace DIM {
  class Caster : public Enemy {
  private:
    float max_speed_x;
    float max_speed_y;
    int delay;
  public:
    Caster();
    ~Caster();

    void update(float elapsedTime) override;
    void draw() const override;
    void initializeSpecific() override;

    void collided(std::string Id, VectorF position, VectorF size) override;
    void adjust() override;

    std::string getID() const override;
  };

}

#endif