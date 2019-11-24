#ifndef THEPENITENTMEMENTO_HPP
#define THEPENITENTMEMENTO_HPP

#include "Memento.hpp"
#include "../Utils/GeometricVector.hpp"

namespace DIM {

  namespace Entities {
    class ThePenitent;
  }

  namespace Mementos {
  
    class ThePenitentMemento : public Memento {
    private:
      ThePenitentMemento(Utils::VectorF pos = Utils::VectorF(0, 0), float ang = 0, float rad = 0);

      Utils::VectorF position;
      float angle;
      float radius;

      Utils::VectorF getPosition() const;
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