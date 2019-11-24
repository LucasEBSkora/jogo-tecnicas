#ifndef LEAPER_HPP
#define LEAPER_HPP

#include "Enemy.hpp"
#include "../Mementos/LeaperMemento.hpp"

namespace DIM {
  namespace Entities {
    namespace Mobs {

      class Leaper : public Enemy {
      private:
        float max_speed_x;
        float max_speed_y;
        bool jumping;
        int delay;
      public:
        Leaper();
        ~Leaper();

        void update(float elapsedTime) override;

        void collided(std::string other_id, Utils::VectorF positionOther, Utils::VectorF size) override;
        void adjust() override;

        Mementos::LeaperMemento createMemento() const;
        void loadMemento(Mementos::LeaperMemento memento);
      };
    }

  }
}

#endif