#include "TheMirrorOfHastur.hpp"

#include "../Levels/Level.hpp"
#include <iostream>

namespace DIM {

  const char* TheMirrorOfHastur::path{"assets/TheMirrorOfHastur.png"};

  TheMirrorOfHastur::TheMirrorOfHastur() : PhysicalEntity(), boundToPlayer{false} {
    id = std::string("Mirror");
  }

  TheMirrorOfHastur::~TheMirrorOfHastur() {

  }

  void TheMirrorOfHastur::initializeSpecific() {
    currentLevel->getGraphicsManager()->loadAsset(path);
    VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset(path);
    width = size.x;
    height = size.y;
    initialPosition = currentLevel->getItemSpawn();
  }

  void TheMirrorOfHastur::update(float elapsedTime)  {
    if (!boundToPlayer) position = initialPosition;
    else position = currentLevel->getPlayer1Center();
    std::cout << "mirror: " << position << std::endl;
  }

  void TheMirrorOfHastur::collided(std::string id, VectorF positionOther, VectorF size) {
      
      boundToPlayer = (id == "Player1" || id == "Player2");

  }

  void TheMirrorOfHastur::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw(path, position);
    } else {
      std::cout << "desenhando objeto nao inicializado\n";
    }
  }

    
}