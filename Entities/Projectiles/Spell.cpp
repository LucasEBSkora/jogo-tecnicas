#include "Spell.hpp"

#include <iostream>

namespace DIM {

  Spell::Spell(VectorF position, VectorF speed) : Projectile(position, speed, "assets/Spell.png")  { 

    id = "Spell";
  }
  
  Spell::~Spell(){ 

  }


  void Spell::collided(std::string other_id, VectorF position, VectorF size) {
    
    if (other_id != "Caster" && other_id != "Projectile" && other_id != "Boss" && other_id != "Spell") Projectile::collided(other_id, position, size);
  }
  
}