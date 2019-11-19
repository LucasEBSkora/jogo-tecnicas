#ifndef CASTER_HPP
#define CASTER_HPP

#include "Enemy.hpp"
#include "../Mementos/CasterMemento.hpp"

namespace DIM {
  class Caster : public Enemy {
  
  private:
  
    static const float spellSpeed;

    float max_speed_x;
    float max_speed_y;
    int delay;
  public:
    Caster();
    ~Caster();

    void update(float elapsedTime) override;

    void collided(std::string Id, VectorF position, VectorF size) override;
    void adjust() override;

    CasterMemento createMemento() const;
    void loadMemento(CasterMemento memento);
  };

}

#endif