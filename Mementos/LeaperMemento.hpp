#ifndef LEAPERMEMENTO_HPP
#define LEAPERMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class Leaper;
  }

  namespace Mementos {
      
    class LeaperMemento : public Memento {
    private:
      LeaperMemento(Utility::VectorF pos = Utility::VectorF(0, 0), Utility::VectorF vel = Utility::VectorF(0, 0), float dly = 0, float max_vx = 0, float max_vy = 0, bool jmp = false);

      Utility::VectorF position;
      Utility::VectorF velocity;
      float delay;
      float max_speed_x;
      float max_speed_y;
      bool jumping;

      Utility::VectorF getPosition() const;
      Utility::VectorF getVelocity() const;
      float getDelay() const;
      float getMaxSpeedX() const;
      float getMaxSpeedY() const;
      bool getJumping() const;

    public:
      ~LeaperMemento();

      void saveToFile(std::ostream& file) override;
      static LeaperMemento loadFromFile(std::istream& file);

      friend class Entities::Leaper;
    };
  
  }
}

#endif