#ifndef CASTERMEMENTO_HPP
#define CASTERMEMENTO_HPP

#include "Memento.hpp"
#include "../Utils/GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    namespace Mobs {
      class Caster;
    }
  }

  namespace Mementos {
      
    class CasterMemento : public Memento {
    private:

      Utils::VectorF position;
      Utils::VectorF velocity;
      float delay;
      float max_speed_x;
      float max_speed_y;
      
      CasterMemento(Utils::VectorF pos = Utils::VectorF(0, 0), Utils::VectorF vel = Utils::VectorF(0, 0), float dly = 0, float max_vx = 0, float max_vy = 0);

      Utils::VectorF getPosition() const;
      Utils::VectorF getVelocity() const;
      float getDelay() const;
      float getMaxSpeedX() const;
      float getMaxSpeedY() const;

    public:
      ~CasterMemento();

      void saveToFile(std::ostream& file) override;
      static CasterMemento loadFromFile(std::istream& file);

      friend class Entities::Mobs::Caster;
    };
  
  }
}

#endif