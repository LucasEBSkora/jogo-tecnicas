#ifndef BULLETMEMENTO_HPP
#define BULLETMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class Bullet;
  }

  namespace Mementos {
      
    class BulletMemento : public Memento {
    private:
      BulletMemento(Utils::VectorF pos = Utils::VectorF(0, 0), Utils::VectorF spd = Utils::VectorF(0, 0), float dly = 0);

      Utils::VectorF position;
      Utils::VectorF speed;
      float delay;

      Utils::VectorF getPosition() const;
      Utils::VectorF getSpeed() const;
      float getDelay() const;

    public:
      ~BulletMemento();

      void saveToFile(std::ostream& file) override;
      static BulletMemento loadFromFile(std::istream& file);

      friend class Entities::Bullet;
    };
  
  }
}

#endif