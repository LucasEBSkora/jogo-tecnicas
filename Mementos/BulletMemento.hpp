#ifndef BULLETMEMENTO_HPP
#define BULLETMEMENTO_HPP

#include "Memento.hpp"
#include "../Vector.hpp"

namespace DIM
{
  class BulletMemento : public Memento {
  private:
    BulletMemento(VectorF pos = VectorF(0, 0), VectorF spd = VectorF(0, 0), float dly = 0);

    VectorF position;
    VectorF speed;
    float delay;

    VectorF getPosition() const;
    VectorF getSpeed() const;
    float getDelay() const;

  public:
    ~BulletMemento();

    void saveToFile(std::ostream& file) override;
    static BulletMemento loadFromFile(std::istream& file);

    friend class Bullet;
  };
  
} // namespace DIM

#endif