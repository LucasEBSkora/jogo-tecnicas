#ifndef THEUNDYINGMEMENTO_HPP
#define THEUNDYINGMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class TheUndying;
  }

  namespace Mementos {
      
    class TheUndyingMemento : public Memento {
    private:
      TheUndyingMemento(Utility::VectorF pos = Utility::VectorF(0, 0), Utility::VectorF vel = Utility::VectorF(0, 0), float max_vx = 0, float max_vy = 0, bool jmp = false, unsigned int deaths = 0);

      Utility::VectorF position;
      Utility::VectorF velocity;
      float max_speed_x;
      float max_speed_y;
      bool jumping;
      unsigned int deathCounter;

      Utility::VectorF getPosition() const;
      Utility::VectorF getVelocity() const;
      float getMaxSpeedX() const;
      float getMaxSpeedY() const;
      bool getJumping() const;
      unsigned int getDeathCounter() const;

    public:
      ~TheUndyingMemento();

      void saveToFile(std::ostream& file) override;
      static TheUndyingMemento loadFromFile(std::istream& file);

      friend class Entities::TheUndying;
    };

  } 
}

#endif