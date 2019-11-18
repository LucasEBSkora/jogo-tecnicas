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
    void draw() const override;
    void initializeSpecific() override;

    void collided(std::string Id, VectorF position, VectorF size) override;
    void adjust() override;

    std::string getID() const override;

    LeaperMemento createMemento() const;
    void loadMemento(LeaperMemento memento);
  };

}

#endif