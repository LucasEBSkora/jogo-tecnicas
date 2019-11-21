#ifndef THEMIRROROFHASTURMEMENTO_HPP
#define THEMIRROROFHASTURMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class TheMirrorOfHastur;
  }

  namespace Mementos {
      
    class TheMirrorOfHasturMemento : public Memento {
    private:
      TheMirrorOfHasturMemento(Utility::VectorF pos = Utility::VectorF(0, 0), bool bound = false);

      Utility::VectorF position;
      bool boundToPlayer;

      Utility::VectorF getPosition() const;
      bool getBoundToPlayer() const;

    public:
      ~TheMirrorOfHasturMemento();

      void saveToFile(std::ostream& file) override;
      static TheMirrorOfHasturMemento loadFromFile(std::istream& file);

      friend class Entities::TheMirrorOfHastur;
    };
  
  }
}

#endif