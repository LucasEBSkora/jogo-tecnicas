#ifndef SPELLMEMENTO_HPP
#define SPELLMEMENTO_HPP

#include "Memento.hpp"
#include "../Vector.hpp"

namespace DIM
{
  class SpellMemento : public Memento {
  private:
    SpellMemento(VectorF pos = VectorF(0, 0), VectorF spd = VectorF(0, 0));

    VectorF position;
    VectorF speed;

    VectorF getPosition() const;
    VectorF getSpeed() const;

  public:
    ~SpellMemento();

    void saveToFile(std::ostream& file) override;
    static SpellMemento loadFromFile(std::istream& file);

    friend class Spell;
  };
  
} // namespace DIM

#endif