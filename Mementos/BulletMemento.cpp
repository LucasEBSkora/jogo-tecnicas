#include "BulletMemento.hpp"

namespace DIM {
  namespace Mementos {
    
    BulletMemento::BulletMemento(Utils::VectorF pos, Utils::VectorF spd, float dly) {
      position = pos;
      speed = spd;
      delay = dly;
    }

    Utils::VectorF BulletMemento::getPosition() const {
      return position;
    }

    Utils::VectorF BulletMemento::getSpeed() const {
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