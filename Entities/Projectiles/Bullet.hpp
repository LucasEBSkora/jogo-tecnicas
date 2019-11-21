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
      Bullet(Utility::VectorF position = Utility::VectorF(0.0f, 0.0f), Utility::VectorF Speed = Utility::VectorF(0.0f, 0.0f));
      ~Bullet();
      void collided(std::string Id, Utility::VectorF position, Utility::VectorF size) override;
      void update(float elapsedTime) override;
      
      Mementos::BulletMemento createMemento() const;
      void loadMemento(Mementos::BulletMemento memento);
    };

  }
}

#endif