#ifndef THEUNDYING_HPP
#define THEUNDYING_HPP

#include "../Mob.hpp"

namespace DIM {
  //Player 1
  class TheUndying : public Mob {
  private:

  public:
    TheUndying();
    ~TheUndying();

    void update(float elapsedTime) override;
    void draw() const override;
    void initializeSpecific() override;
  };
}

#endif