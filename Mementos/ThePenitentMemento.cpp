#include "ThePenitentMemento.hpp"

namespace DIM {
  namespace Mementos {

    ThePenitentMemento::ThePenitentMemento(Utility::VectorF pos, float ang, float rad) {
      position = pos;
      angle = ang;
      radius = rad;
    }

    Utility::VectorF ThePenitentMemento::getPosition() const {
      return position;
    }

    float ThePenitentMemento::getAngle() const {
      return angle;
    }
    
    float ThePenitentMemento::getRadius() const {
      return radius;
    }
    
    ThePenitentMemento::~ThePenitentMemento() {

    }

    void ThePenitentMemento::saveToFile(std::ostream& file) {
      file << position.x << ' ' << position.y << ' ' <<
              angle << ' ' << 
              radius << '\n';
    }

    ThePenitentMemento ThePenitentMemento::loadFromFile(std::istream& file) {
      ThePenitentMemento memento;
      file >> memento.position.x >> memento.position.y >>
              memento.angle >>
              memento.radius;
      return memento;
    }

  }
}