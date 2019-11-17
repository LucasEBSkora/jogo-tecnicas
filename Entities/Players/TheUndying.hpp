#ifndef THEUNDYING_HPP
#define THEUNDYING_HPP

#include "../Mob.hpp"

namespace DIM {
  //Player 1
  class TheUndying : public Mob {
  private:
    float max_speed_x;
    float max_speed_y;
    int movement_id;
    bool pressed[4];
    bool jumping;
    unsigned int deathCounter;
  public:
    TheUndying();
    ~TheUndying();

    void update(float elapsedTime) override;
    void draw() const override;
    void initializeSpecific() override;

    void unsubscribe();

    void collided(std::string Id, VectorF position, VectorF size) override;
    void adjust() override;

    std::string getID() const override;
  };
}

#endif