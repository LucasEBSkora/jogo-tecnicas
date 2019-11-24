#ifndef THEUNDYINGMEMENTO_HPP
#define THEUNDYINGMEMENTO_HPP

#include "Memento.hpp"
#include "../Utils/GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    namespace Mobs {
      class TheUndying;
    }
  }

  namespace Mementos {
      
    class TheUndyingMemento : public Memento {
    private:
      TheUndyingMemento(Utils::VectorF pos = Utils::VectorF(0, 0), Utils::VectorF vel = Utils::VectorF(0, 0), float max_vx = 0, float max_vy = 0, bool jmp = false, unsigned int deaths = 0);

      Utils::VectorF position;
      Utils::VectorF velocity;
      float max_speed_x;
      float max_speed_y;
      bool jumping;
      unsigned int deathCounter;

      Utils::VectorF getPosition() const;
      Utils::VectorF getVelocity() const;
      float getMaxSpeedX() const;
      float getMaxSpeedY() const;
      bool getJumping() const;
      unsigned int getDeathCounter() const;

    public:
      ~TheUndyingMemento();

      void saveToFile(std::ostream& file) override;
      static TheUndyingMemento loadFromFile(std::istream& file);

      friend class Entities::Mobs::TheUndying;
    };

  } 
}

#endif