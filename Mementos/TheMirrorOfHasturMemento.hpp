#ifndef THEMIRROROFHASTURMEMENTO_HPP
#define THEMIRROROFHASTURMEMENTO_HPP

#include "Memento.hpp"
#include "../Vector.hpp"

namespace DIM
{
  class TheMirrorOfHasturMemento : public Memento {
  private:
    TheMirrorOfHasturMemento(VectorF pos = VectorF(0, 0), bool bound = false);

    VectorF position;
    bool boundToPlayer;

    VectorF getPosition() const;
    bool getBoundToPlayer() const;

  public:
    TheMirrorOfHasturMemento(const TheMirrorOfHasturMemento&) = default;
    ~TheMirrorOfHasturMemento();

    void saveToFile(std::ostream& file) override;
    static TheMirrorOfHasturMemento loadFromFile(std::istream& file);

    friend class TheMirrorOfHastur;
  };
  
} // namespace DIM

#endif