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
      BulletMemento(Utility::VectorF pos = Utility::VectorF(0, 0), Utility::VectorF spd = Utility::VectorF(0, 0), float dly = 0);

      Utility::VectorF position;
      Utility::VectorF speed;
      float delay;

      Utility::VectorF getPosition() const;
      Utility::VectorF getSpeed() const;
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