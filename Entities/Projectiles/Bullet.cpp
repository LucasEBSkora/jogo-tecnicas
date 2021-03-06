#include "Bullet.hpp"

namespace DIM {
  namespace Entities {
    namespace Projectiles {
      Bullet::Bullet(Utils::VectorF position, Utils::VectorF speed) : Projectile(position, speed, "assets/Bullet.png"), delay{0.2f}  { 
        id = "Bullet";
      }
      
      Bullet::~Bullet(){ 

      }

      void Bullet::collided(std::string Id, Utils::VectorF positionOther, Utils::VectorF size) {
        if (Id == "Player1" || Id == "Player2")
          Projectile::collided(Id, position, size);
        else if (delay <= 0) 
          Projectile::collided(Id, position, size);
      }

      void Bullet::update(float elapsedTime) {
        Projectile::update(elapsedTime);
        if (delay > 0) delay -= elapsedTime;
      }

      Mementos::BulletMemento Bullet::createMemento() const {
        Mementos::BulletMemento memento(position, speed, delay);
        return memento;
      }

      void Bullet::loadMemento(Mementos::BulletMemento memento) {
        position = memento.getPosition();
        speed = memento.getSpeed();
        delay = memento.getDelay();
      }
    }

  }
}