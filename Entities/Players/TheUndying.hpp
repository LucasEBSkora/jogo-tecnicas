#ifndef THEUNDYING_HPP
#define THEUNDYING_HPP

#include "../Mob.hpp"

namespace DIM {
  //Player 1
  class TheUndying : public Mob {
  private:
    float max_speed;
    int movement_id;
    bool pressed[4];
  public:
    TheUndying();
    ~TheUndying();

    void update(float elapsedTime) override;
    void draw() const override;
    void initializeSpecific() override;

    void collided(std::string Id, VectorF position, VectorF size) override;

    std::string getID() const override;
  };
}

#endif