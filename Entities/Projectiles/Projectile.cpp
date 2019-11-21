#include "Projectile.hpp"

#include <iostream>
#include "../../Levels/Level.hpp"

namespace DIM {
  namespace Entities {

    Projectile::Projectile(Utility::VectorF position, Utility::VectorF Speed, const char* Path) 
    : speed{Speed}, path{Path}  {
        id = "Projectile";
        setPos(position);
      
    }
    
    Projectile::~Projectile() {

    }

    void Projectile::update(float elapsedTime) {
      position += speed * elapsedTime;
    }

    void Projectile::draw() const {
      if (currentLevel != nullptr) {
        currentLevel->getGraphicsManager()->draw(path, position);
      } else {
        std::cout << "desenhando objeto nao inicializado\n";
      }
    }

    void Projectile::initializeSpecific() {
      currentLevel->getGraphicsManager()->loadAsset(path);
      Utility::VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset(path);
      width = size.x;
      height = size.y;
    }

    void Projectile::collided(std::string other_id, Utility::VectorF positionOther, Utility::VectorF size) {
      destroySelf();
    }

    void Projectile::adjust() {

    }

    
    void Projectile::setSpeed(Utility::VectorF Speed) {
      speed = Speed;
    }

    void Projectile::destroySelf() {
      currentLevel->markForDelete(this);
      
    }

  }
}