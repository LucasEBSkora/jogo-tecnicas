#include "Spell.hpp"

namespace DIM {

  Spell::Spell(VectorF position, VectorF speed) : Projectile(position, speed, "assets/Spell.png")  { 

  }
  
  Spell::~Spell(){ 

  }

  void Spell::collided(std::string other_id, VectorF position, VectorF size) {
    
    if (other_id != "Caster" && other_id != "Projectile") Projectile::collided(other_id, position, size);
  }
  
}