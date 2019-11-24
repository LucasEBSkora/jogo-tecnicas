#ifndef LEAPERMEMENTO_HPP
#define LEAPERMEMENTO_HPP

#include "Memento.hpp"
#include "../Utils/GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    namespace Mobs {
      class Leaper;
    }
  }

  namespace Mementos {
      
    class LeaperMemento : public Memento {
    private:

      Utils::VectorF position;
      Utils::VectorF velocity;
      float delay;
      float max_speed_x;
      float max_speed_y;
      bool jumping;
      
      LeaperMemento(Utils::VectorF pos = Utils::VectorF(0, 0), Utils::VectorF vel = Utils::VectorF(0, 0), float dly = 0, float max_vx = 0, float max_vy = 0, bool jmp = false);

      Utils::VectorF getPosition() const;
      Utils::VectorF getVelocity() const;
      float getDelay() const;
      float getMaxSpeedX() const;
      float getMaxSpeedY() const;
      bool getJumping() const;

    public:
      ~LeaperMemento();

      void saveToFile(std::ostream& file) override;
      static LeaperMemento loadFromFile(std::istream& file);

      friend class Entities::Mobs::Leaper;
    };
  
  }
}

#endif