#include "SpellMemento.hpp"

namespace DIM {
  namespace Mementos {
  
    SpellMemento::SpellMemento(Utils::VectorF pos, Utils::VectorF spd) {
      position = pos;
      speed = spd;
    }

    Utils::VectorF SpellMemento::getPosition() const {
      return position;
    }

    Utils::VectorF SpellMemento::getSpeed() const {
      return speed;
    }
    
    SpellMemento::~SpellMemento() {

    }

    void SpellMemento::saveToFile(std::ostream& file) {
      file << position.x << ' ' << position.y << ' ' <<
              speed.x << ' ' << speed.y << '\n';
    }

    SpellMemento SpellMemento::loadFromFile(std::istream& file) {
      SpellMemento memento;
      file >> memento.position.x >> memento.position.y >>
              memento.speed.x >> memento.speed.y;
      return memento;
    }

  }
}