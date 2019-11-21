#ifndef CASTERMEMENTO_HPP
#define CASTERMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class Caster;
  }

  namespace Mementos {
      
    class CasterMemento : public Memento {
    private:
      CasterMemento(Utility::VectorF pos = Utility::VectorF(0, 0), Utility::VectorF vel = Utility::VectorF(0, 0), float dly = 0, float max_vx = 0, float max_vy = 0);

      Utility::VectorF position;
      Utility::VectorF velocity;
      float delay;
      float max_speed_x;
      float max_speed_y;

      Utility::VectorF getPosition() const;
      Utility::VectorF getVelocity() const;
      float getDelay() const;
      float getMaxSpeedX() const;
      float getMaxSpeedY() const;

    public:
      ~CasterMemento();

      void saveToFile(std::ostream& file) override;
      static CasterMemento loadFromFile(std::istream& file);

      friend class Entities::Caster;
    };
  
  }
}

#endif