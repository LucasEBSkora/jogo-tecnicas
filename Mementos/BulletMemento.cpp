#include "BulletMemento.hpp"

namespace DIM {
  namespace Mementos {
    
    BulletMemento::BulletMemento(Utility::VectorF pos, Utility::VectorF spd, float dly) {
      position = pos;
      speed = spd;
      delay = dly;
    }

    Utility::VectorF BulletMemento::getPosition() const {
      return position;
    }

    Utility::VectorF BulletMemento::getSpeed() const {
      return speed;
    }

    float BulletMemento::getDelay() const {
      return delay;
    }
    
    BulletMemento::~BulletMemento() {

    }

    void BulletMemento::saveToFile(std::ostream& file) {
      file << position.x << ' ' << position.y << ' ' <<
              speed.x << ' ' << speed.y << ' ' <<
              delay << '\n';
    }

    BulletMemento BulletMemento::loadFromFile(std::istream& file) {
      BulletMemento memento;
      file >> memento.position.x >> memento.position.y >>
              memento.speed.x >> memento.speed.y >>
              memento.delay;
      return memento;
    }

  }
}