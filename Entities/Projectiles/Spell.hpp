#ifndef SPELL_HPP
#define SPELL_HPP

#include "Projectile.hpp"
#include "../Mementos/SpellMemento.hpp"

namespace DIM {
  namespace Entities {
      
    class Spell : public Projectile {
    private:

    public:
      Spell(Utility::VectorF position = Utility::VectorF(0.0f, 0.0f), Utility::VectorF speed = Utility::VectorF(0.0f, 0.0f));
      ~Spell();
      void collided(std::string other_id, Utility::VectorF position, Utility::VectorF size) override;
      
      Mementos::SpellMemento createMemento() const;
      void loadMemento(Mementos::SpellMemento memento);
    };

  }
}

#endif