#ifndef SPELLMEMENTO_HPP
#define SPELLMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class Spell;
  }

  namespace Mementos {
      
    class SpellMemento : public Memento {
    private:
      SpellMemento(Utility::VectorF pos = Utility::VectorF(0, 0), Utility::VectorF spd = Utility::VectorF(0, 0));

      Utility::VectorF position;
      Utility::VectorF speed;

      Utility::VectorF getPosition() const;
      Utility::VectorF getSpeed() const;

    public:
      ~SpellMemento();

      void saveToFile(std::ostream& file) override;
      static SpellMemento loadFromFile(std::istream& file);

      friend class Entities::Spell;
    };
  
  }
}

#endif