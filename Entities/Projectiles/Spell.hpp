#ifndef SPELL_HPP
#define SPELL_HPP

#include "Projectile.hpp"
#include "../Mementos/SpellMemento.hpp"

namespace DIM {
  class Spell : public Projectile {
  private:

  public:
    Spell(VectorF position = VectorF(0.0f, 0.0f), VectorF speed = VectorF(0.0f, 0.0f));
    ~Spell();
    void collided(std::string other_id, VectorF position, VectorF size) override;
    
    SpellMemento createMemento() const;
    void loadMemento(SpellMemento memento);
  };

}

#endif