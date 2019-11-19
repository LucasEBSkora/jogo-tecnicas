#include "TheUndyingMemento.hpp"
#include <iostream>

namespace DIM {
  
  TheUndyingMemento::TheUndyingMemento(VectorF pos, VectorF vel, float max_vx, float max_vy, bool jmp, unsigned int deaths) {
    position = pos;
    velocity = vel;
    max_speed_x = max_vx;
    max_speed_y = max_vy;
    jumping = jmp;
    deathCounter = deaths;
  }

  VectorF TheUndyingMemento::getPosition() const {
    return position;
  }

  VectorF TheUndyingMemento::getVelocity() const {
    return velocity;
  }
  
  float TheUndyingMemento::getMaxSpeedX() const {
    return max_speed_x;
  }
  
  float TheUndyingMemento::getMaxSpeedY() const {
    return max_speed_y;
  }
  
  bool TheUndyingMemento::getJumping() const {
    return jumping;
  }
  
  unsigned int TheUndyingMemento::getDeathCounter() const {
    return deathCounter;
  }
  
  TheUndyingMemento::~TheUndyingMemento() {

  }

  void TheUndyingMemento::saveToFile(std::ostream& file) {
    file << position.x << ' ' << position.y << ' ' <<
            velocity.x << ' ' << velocity.y << ' ' <<
            max_speed_x << ' ' << max_speed_y << ' ' <<
            jumping << ' ' <<
            deathCounter << '\n';
  }

  TheUndyingMemento TheUndyingMemento::loadFromFile(std::istream& file) {
    TheUndyingMemento memento;
    file >> memento.position.x >> memento.position.y >>
            memento.velocity.x >> memento.velocity.y >>
            memento.max_speed_x >> memento.max_speed_y >>
            memento.jumping >>
            memento.deathCounter;
    return memento;
  }

}