#include "SpellMemento.hpp"

namespace DIM {
  
  SpellMemento::SpellMemento(VectorF pos, VectorF spd) {
    position = pos;
    speed = spd;
  }

  VectorF SpellMemento::getPosition() const {
    return position;
  }

  VectorF SpellMemento::getSpeed() const {
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
  }

}