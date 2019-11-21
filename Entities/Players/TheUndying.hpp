#ifndef THEUNDYING_HPP
#define THEUNDYING_HPP

#include "../Mob.hpp"
#include "../Mementos/TheUndyingMemento.hpp"

namespace DIM {
  namespace Entities {
    
    //Player 1
    class TheUndying : public Mob {
    private:
      float max_speed_x;
      float max_speed_y;
      int movement_id;
      bool pressed[2];
      bool jumping;
      unsigned int deathCounter;
    public:
      TheUndying();
      ~TheUndying();

      void update(float elapsedTime) override;
      void draw() const override;
      void initializeSpecific() override;

      void collided(std::string Id, Utility::VectorF position, Utility::VectorF size) override;
      void adjust() override;
      
      Mementos::TheUndyingMemento createMemento() const;
      void loadMemento(Mementos::TheUndyingMemento memento);
    };

  }
}

#endif