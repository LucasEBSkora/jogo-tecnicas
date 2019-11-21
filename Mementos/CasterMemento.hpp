#ifndef CASTERMEMENTO_HPP
#define CASTERMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"

namespace DIM
{
  class CasterMemento : public Memento {
  private:
    CasterMemento(VectorF pos = VectorF(0, 0), VectorF vel = VectorF(0, 0), float dly = 0, float max_vx = 0, float max_vy = 0);

    VectorF position;
    VectorF velocity;
    float delay;
    float max_speed_x;
    float max_speed_y;

    VectorF getPosition() const;
    VectorF getVelocity() const;
    float getDelay() const;
    float getMaxSpeedX() const;
    float getMaxSpeedY() const;

  public:
    ~CasterMemento();

    void saveToFile(std::ostream& file) override;
    static CasterMemento loadFromFile(std::istream& file);

    friend class Caster;
  };
  
} // namespace DIM

#endif