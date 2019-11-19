#ifndef THEPENITENT_HPP
#define THEPENITENT_HPP

#include "../Mob.hpp"
#include "../Mementos/ThePenitentMemento.hpp"

namespace DIM {
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

    void collided(std::string Id, VectorF position, VectorF size) override;
    void unsubscribe();
    ThePenitentMemento createMemento() const;
    void loadMemento(ThePenitentMemento memento);
  };

}

#endif