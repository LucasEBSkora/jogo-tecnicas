#ifndef CASTER_HPP
#define CASTER_HPP

#include "Enemy.hpp"
#include "../Mementos/CasterMemento.hpp"

namespace DIM {
  namespace Entities {

    class Caster : public Enemy {
    protected:
    
      static const float spellSpeed;

      float max_speed_x;
      float max_speed_y;
      int delay;
    public:
      Caster();
      ~Caster();

      void update(float elapsedTime) override;

      void collided(std::string other_id, Utils::VectorF positionOther, Utils::VectorF size) override;
      void adjust() override;

      Mementos::CasterMemento createMemento() const;
      void loadMemento(Mementos::CasterMemento memento);
    };

  }
}

#endif