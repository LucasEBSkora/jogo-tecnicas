#ifndef SPELLMEMENTO_HPP
#define SPELLMEMENTO_HPP

#include "Memento.hpp"
#include "../Utils/GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    namespace Projectiles {
      class Spell;
    }
  }

  namespace Mementos {
      
    class SpellMemento : public Memento {
    private:
      SpellMemento(Utils::VectorF pos = Utils::VectorF(0, 0), Utils::VectorF spd = Utils::VectorF(0, 0));

      Utils::VectorF position;
      Utils::VectorF speed;

      Utils::VectorF getPosition() const;
      Utils::VectorF getSpeed() const;

    public:
      ~SpellMemento();

      void saveToFile(std::ostream& file) override;
      static SpellMemento loadFromFile(std::istream& file);

      friend class Entities::Projectiles::Spell;
    };
  
  }
}

#endif