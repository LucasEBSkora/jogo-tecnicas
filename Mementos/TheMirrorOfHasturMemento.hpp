#ifndef THEMIRROROFHASTURMEMENTO_HPP
#define THEMIRROROFHASTURMEMENTO_HPP

#include "Memento.hpp"
#include "../Utils/GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class TheMirrorOfHastur;
  }

  namespace Mementos {
      
    class TheMirrorOfHasturMemento : public Memento {
    private:
      TheMirrorOfHasturMemento(Utils::VectorF pos = Utils::VectorF(0, 0), bool bound = false);

      Utils::VectorF position;
      bool boundToPlayer;

      Utils::VectorF getPosition() const;
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