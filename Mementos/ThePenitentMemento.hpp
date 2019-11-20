#ifndef THEPENITENTMEMENTO_HPP
#define THEPENITENTMEMENTO_HPP

#include "Memento.hpp"
#include "../Vector.hpp"

namespace DIM
{
  class ThePenitentMemento : public Memento {
  private:
    ThePenitentMemento(VectorF pos = VectorF(0, 0), float ang = 0, float rad = 0);

    VectorF position;
    float angle;
    float radius;

    VectorF getPosition() const;
    float getAngle() const;
    float getRadius() const;
    
  public:
    ~ThePenitentMemento();

    void saveToFile(std::ostream& file) override;
    static ThePenitentMemento loadFromFile(std::istream& file);

    friend class ThePenitent;
  };
  
} // namespace DIM

#endif