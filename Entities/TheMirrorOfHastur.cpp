#include "TheMirrorOfHastur.hpp"

#include "../Levels/Level.hpp"
#include <iostream>

namespace DIM {
  namespace Entities {

    TheMirrorOfHastur::TheMirrorOfHastur() : PhysicalEntity("assets/TheMirrorOfHastur.png"), boundToPlayer{false} {
      id = std::string("Mirror");
    }

    TheMirrorOfHastur::~TheMirrorOfHastur() {

    }

    void TheMirrorOfHastur::initializeSpecific() {
      currentLevel->getGraphicsManager()->loadAsset(path);
      Utils::VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset(path);
      width = size.x;
      height = size.y;
      initialPosition = currentLevel->getItemSpawn();
    }

    void TheMirrorOfHastur::update(float elapsedTime)  {
      if (!boundToPlayer) position = initialPosition;
      else position = currentLevel->getPlayer1Center();
    }

    void TheMirrorOfHastur::collided(std::string id, Utils::VectorF positionOther, Utils::VectorF size) {
        
        if (id == "Player1" || id == "Player2") {
          boundToPlayer = true;
        }

    }

    const bool TheMirrorOfHastur::isBound() const {
      return boundToPlayer;
    }
    

    Mementos::TheMirrorOfHasturMemento TheMirrorOfHastur::createMemento() const {
      Mementos::TheMirrorOfHasturMemento memento(position, boundToPlayer);
      return memento;
    }

    void TheMirrorOfHastur::loadMemento(Mementos::TheMirrorOfHasturMemento memento) {
      position = memento.getPosition();
      boundToPlayer = memento.getBoundToPlayer();
    }
  
  }
}