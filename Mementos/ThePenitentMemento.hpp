#ifndef THEPENITENTMEMENTO_HPP
#define THEPENITENTMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class ThePenitent;
  }

  namespace Mementos {
  
    class ThePenitentMemento : public Memento {
    private:
      ThePenitentMemento(Utility::VectorF pos = Utility::VectorF(0, 0), float ang = 0, float rad = 0);

      Utility::VectorF position;
      float angle;
      float radius;

      Utility::VectorF getPosition() const;
      float getAngle() const;
      float getRadius() const;
      
    public:
      ~ThePenitentMemento();

      void saveToFile(std::ostream& file) override;
      static ThePenitentMemento loadFromFile(std::istream& file);

      friend class Entities::ThePenitent;
    };

  } 
}

#endif