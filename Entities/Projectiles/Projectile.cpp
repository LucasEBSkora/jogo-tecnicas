#include "Projectile.hpp"

#include <iostream>
#include "../../Levels/Level.hpp"

namespace DIM {

  Projectile::Projectile(VectorF position, VectorF Speed, const char* Path) 
  : speed{Speed}, path{Path} {
      setPos(position);
    
  }
  
  Projectile::~Projectile() {

  }

  void Projectile::update(float elapsedTime) {
    x += speed.x*elapsedTime;
    y += speed.y*elapsedTime;
  }

  void Projectile::draw() const {
    if (currentLevel != nullptr) {
      currentLevel->getGraphicsManager()->draw(path, VectorF(x, y));
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

  void Projectile::collided(std::string other_id, VectorF position, VectorF size) {
    // he's dead
    
    y -= 2000;
  }

  void Projectile::adjust() {

  }

  std::string Projectile::getID() const {
    return id;
  }
  
  void Projectile::setSpeed(VectorF Speed) {
    speed = Speed;
  }

}