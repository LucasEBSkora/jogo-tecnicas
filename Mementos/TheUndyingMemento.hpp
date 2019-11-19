#ifndef THEUNDYINGMEMENTO_HPP
#define THEUNDYINGMEMENTO_HPP

#include "Memento.hpp"
#include "../Vector.hpp"

namespace DIM
{
  class TheUndyingMemento : public Memento {
  private:
    TheUndyingMemento(VectorF pos = VectorF(0, 0), VectorF vel = VectorF(0, 0), float max_vx = 0, float max_vy = 0, bool jmp = false, unsigned int deaths = 0);

    VectorF position;
    VectorF velocity;
    float max_speed_x;
    float max_speed_y;
    bool jumping;
    unsigned int deathCounter;

    VectorF getPosition() const;
    VectorF getVelocity() const;
    float getMaxSpeedX() const;
    float getMaxSpeedY() const;
    bool getJumping() const;
    unsigned int getDeathCounter() const;

  public:
    TheUndyingMemento(const TheUndyingMemento&) = default;
    ~TheUndyingMemento();

    void saveToFile(std::ostream& file) override;
    static TheUndyingMemento loadFromFile(std::istream& file);

    friend class TheUndying;
  };
  
} // namespace DIM

#endif