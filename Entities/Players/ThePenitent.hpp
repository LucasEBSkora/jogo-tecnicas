#ifndef THEPENITENT_HPP
#define THEPENITENT_HPP

#include "../Mob.hpp"
#include "../Mementos/ThePenitentMemento.hpp"

namespace DIM {
  namespace Entities {
      
    class ThePenitent : public Mob {
    private:
      int movement_id;
      float angle;
      float radius;
    public:
      ThePenitent();
      ~ThePenitent();

      void update(float elapsedTime) override;
      void draw() const override;
      void initializeSpecific() override;

      void collided(std::string Id, Utils::VectorF position, Utils::VectorF size) override;
      
      Mementos::ThePenitentMemento createMemento() const;
      void loadMemento(Mementos::ThePenitentMemento memento);
    };

  }
}

#endif