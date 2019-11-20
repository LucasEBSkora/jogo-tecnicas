#ifndef LEAPER_HPP
#define LEAPER_HPP

#include "Enemy.hpp"
#include "../Mementos/LeaperMemento.hpp"

namespace DIM {
  class Leaper : public Enemy {
  private:
    float max_speed_x;
    float max_speed_y;
    bool jumping;
    int delay;
  public:
    Leaper();
    ~Leaper();

    void update(float elapsedTime) override;

    void collided(std::string other_id, VectorF positionOther, VectorF size) override;
    void adjust() override;

    LeaperMemento createMemento() const;
    void loadMemento(LeaperMemento memento);
  };

}

#endif