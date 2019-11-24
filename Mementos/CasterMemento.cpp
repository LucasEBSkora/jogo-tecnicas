#include "CasterMemento.hpp"

namespace DIM {
  namespace Mementos {

    CasterMemento::CasterMemento(Utils::VectorF pos, Utils::VectorF vel, float dly, float max_vx, float max_vy) {
      position = pos;
      velocity = vel;
      delay = dly;
      max_speed_x = max_vx;
      max_speed_y = max_vy;
    }

    Utils::VectorF CasterMemento::getPosition() const {
      return position;
    }

    Utils::VectorF CasterMemento::getVelocity() const {
      return velocity;
    }

    float CasterMemento::getDelay() const {
      return delay;
    }
    
    float CasterMemento::getMaxSpeedX() const {
      return max_speed_x;
    }
    
    float CasterMemento::getMaxSpeedY() const {
      return max_speed_y;
    }
    
    CasterMemento::~CasterMemento() {

    }

    void CasterMemento::saveToFile(std::ostream& file) {
      file << position.x << ' ' << position.y << ' ' <<
              velocity.x << ' ' << velocity.y << ' ' <<
              delay << ' ' <<
              max_speed_x << ' ' << max_speed_y << '\n';
    }

    CasterMemento CasterMemento::loadFromFile(std::istream& file) {
      CasterMemento memento;
      file >> memento.position.x >> memento.position.y >>
              memento.velocity.x >> memento.velocity.y >>
              memento.delay >>
              memento.max_speed_x >> memento.max_speed_y;
      return memento;
    }

  }
}