#ifndef THEMIRROROFHASTUR_HPP
#define THEMIRROROFHASTUR_HPP

#include "PhysicalEntity.hpp"
#include "../Mementos/TheMirrorOfHasturMemento.hpp"

namespace DIM {
  namespace Entities {

    class TheMirrorOfHastur : public PhysicalEntity {
      
    private:
      bool boundToPlayer;
      Utils::VectorF initialPosition;
      const char* path;

    public:
      TheMirrorOfHastur();
      ~TheMirrorOfHastur();

      void initializeSpecific() override;
      void update(float elapsedTime) override;
      void collided(std::string id, Utils::VectorF positionOther, Utils::VectorF size) override;
      void draw() const override;
      const bool isBound() const;

      Mementos::TheMirrorOfHasturMemento createMemento() const;
      void loadMemento(Mementos::TheMirrorOfHasturMemento memento);
    };
  
  }
}

#endif