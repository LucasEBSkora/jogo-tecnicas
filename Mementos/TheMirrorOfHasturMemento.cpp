#include "TheMirrorOfHasturMemento.hpp"

namespace DIM {

  TheMirrorOfHasturMemento::TheMirrorOfHasturMemento(VectorF pos, VectorF vel, float dly, float max_vx, float max_vy, bool jmp) {
    position = pos;
    velocity = vel;
    delay = dly;
    max_speed_x = max_vx;
    max_speed_y = max_vy;
    jumping = jmp;
  }

  VectorF TheMirrorOfHasturMemento::getPosition() const {
    return position;
  }

  VectorF TheMirrorOfHasturMemento::getVelocity() const {
    return velocity;
  }

  float TheMirrorOfHasturMemento::getDelay() const {
    return delay;
  }
  
  float TheMirrorOfHasturMemento::getMaxSpeedX() const {
    return max_speed_x;
  }
  
  float TheMirrorOfHasturMemento::getMaxSpeedY() const {
    return max_speed_y;
  }
  
  bool TheMirrorOfHasturMemento::getJumping() const {
    return jumping;
  }
  
  TheMirrorOfHasturMemento::~TheMirrorOfHasturMemento() {

  }

  void TheMirrorOfHasturMemento::saveToFile(std::ostream& file) {
    file << position.x << ' ' << position.y << ' ' <<
            velocity.x << ' ' << velocity.y << ' ' <<
            delay << ' ' <<
            max_speed_x << ' ' << max_speed_y << ' ' <<
            jumping << '\n';
  }

  TheMirrorOfHasturMemento TheMirrorOfHasturMemento::loadFromFile(std::istream& file) {
    TheMirrorOfHasturMemento memento;
    file >> memento.position.x >> memento.position.y >>
            memento.velocity.x >> memento.velocity.y >>
            memento.delay >>
            memento.max_speed_x >> memento.max_speed_y >>
            memento.jumping;
    return memento;
  }

}