#ifndef BULLET_HPP
#define BULLET_HPP

#include "Projectile.hpp"
#include "../Mementos/BulletMemento.hpp"

namespace DIM {
  namespace Entities {
      
    class Bullet : public Projectile {
    private:
      float delay;
    
    public:
      Bullet(Utils::VectorF position = Utils::VectorF(0.0f, 0.0f), Utils::VectorF Speed = Utils::VectorF(0.0f, 0.0f));
      ~Bullet();
      void collided(std::string Id, Utils::VectorF position, Utils::VectorF size) override;
      void update(float elapsedTime) override;
      
      Mementos::BulletMemento createMemento() const;
      void loadMemento(Mementos::BulletMemento memento);
    };

  }
}

#endif