#include "BulletMemento.hpp"

namespace DIM {
  
  BulletMemento::BulletMemento(VectorF pos, VectorF spd, float dly) {
    position = pos;
    speed = spd;
    delay = dly;
  }

  VectorF BulletMemento::getPosition() const {
    return position;
  }

  VectorF BulletMemento::getSpeed() const {
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