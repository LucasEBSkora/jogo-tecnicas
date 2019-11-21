#include "Spell.hpp"

#include <iostream>

namespace DIM {
  namespace Entities {

    Spell::Spell(Utility::VectorF position, Utility::VectorF speed) : Projectile(position, speed, "assets/Spell.png")  { 

      id = "Spell";
    }
    
    Spell::~Spell(){ 

    }


    void Spell::collided(std::string other_id, Utility::VectorF position, Utility::VectorF size) {
      
      if (other_id != "Caster" && other_id != "Projectile" && other_id != "Boss" && other_id != "Spell") Projectile::collided(other_id, position, size);
    }

    Mementos::SpellMemento Spell::createMemento() const {
      Mementos::SpellMemento memento(position, speed);
      return memento;
    }

    void Spell::loadMemento(Mementos::SpellMemento memento) {
      position = memento.getPosition();
      speed = memento.getSpeed();
    }
  
  }
}