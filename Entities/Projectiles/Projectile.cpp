#include "Projectile.hpp"

#include <iostream>
#include "../../Levels/Level.hpp"

namespace DIM {

  Projectile::Projectile(VectorF position, VectorF Speed, const char* Path) 
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
    VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset(path);
    width = size.x;
    height = size.y;
  }

  void Projectile::collided(std::string other_id, VectorF positionOther, VectorF size) {
    // he's dead
    //std::cout << "morri: " << other_id <<  std::endl;
    
    destroySelf();
  }

  void Projectile::adjust() {

  }

  
  void Projectile::setSpeed(VectorF Speed) {
    speed = Speed;
  }

  void Projectile::destroySelf() {
    currentLevel->markForDelete(this);
    
  }

}