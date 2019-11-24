#ifndef SPELL_HPP
#define SPELL_HPP

#include "Projectile.hpp"
#include "../Mementos/SpellMemento.hpp"

namespace DIM {
  namespace Entities {
      
    class Spell : public Projectile {
    private:

    public:
      Spell(Utils::VectorF position = Utils::VectorF(0.0f, 0.0f), Utils::VectorF speed = Utils::VectorF(0.0f, 0.0f));
      ~Spell();
      void collided(std::string other_id, Utils::VectorF position, Utils::VectorF size) override;
      
      Mementos::SpellMemento createMemento() const;
      void loadMemento(Mementos::SpellMemento memento);
    };

  }
}

#endif