#include "LeaperMemento.hpp"

namespace DIM {
  namespace Mementos {

    LeaperMemento::LeaperMemento(Utility::VectorF pos, Utility::VectorF vel, float dly, float max_vx, float max_vy, bool jmp) {
      position = pos;
      velocity = vel;
      delay = dly;
      max_speed_x = max_vx;
      max_speed_y = max_vy;
      jumping = jmp;
    }

    Utility::VectorF LeaperMemento::getPosition() const {
      return position;
    }

    Utility::VectorF LeaperMemento::getVelocity() const {
      return velocity;
    }

    float LeaperMemento::getDelay() const {
      return delay;
    }
    
    float LeaperMemento::getMaxSpeedX() const {
      return max_speed_x;
    }
    
    float LeaperMemento::getMaxSpeedY() const {
      return max_speed_y;
    }
    
    bool LeaperMemento::getJumping() const {
      return jumping;
    }
    
    LeaperMemento::~LeaperMemento() {

    }

    void LeaperMemento::saveToFile(std::ostream& file) {
      file << position.x << ' ' << position.y << ' ' <<
              velocity.x << ' ' << velocity.y << ' ' <<
              delay << ' ' <<
              max_speed_x << ' ' << max_speed_y << ' ' <<
              jumping << '\n';
    }

    LeaperMemento LeaperMemento::loadFromFile(std::istream& file) {
      LeaperMemento memento;
      file >> memento.position.x >> memento.position.y >>
              memento.velocity.x >> memento.velocity.y >>
              memento.delay >>
              memento.max_speed_x >> memento.max_speed_y >>
              memento.jumping;
      return memento;
    }

  }
}