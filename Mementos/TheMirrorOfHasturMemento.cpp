#include "TheMirrorOfHasturMemento.hpp"

namespace DIM {
  namespace Mementos {

    TheMirrorOfHasturMemento::TheMirrorOfHasturMemento(Utility::VectorF pos, bool bound) {
      position = pos;
      boundToPlayer = bound;
    }

    Utility::VectorF TheMirrorOfHasturMemento::getPosition() const {
      return position;
    }

    bool TheMirrorOfHasturMemento::getBoundToPlayer() const {
      return boundToPlayer;
    }
    
    TheMirrorOfHasturMemento::~TheMirrorOfHasturMemento() {

    }

    void TheMirrorOfHasturMemento::saveToFile(std::ostream& file) {
      file << position.x << ' ' << position.y << ' ' <<
              boundToPlayer << '\n';
    }

    TheMirrorOfHasturMemento TheMirrorOfHasturMemento::loadFromFile(std::istream& file) {
      TheMirrorOfHasturMemento memento;
      file >> memento.position.x >> memento.position.y >>
              memento.boundToPlayer;
      return memento;
    }

  }
}