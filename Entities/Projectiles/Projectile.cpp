#include "Projectile.hpp"

#include <iostream>
#include "../../Levels/Level.hpp"

namespace DIM {
  namespace Entities {
    namespace Projectiles {

      Projectile::Projectile(Utils::VectorF position, Utils::VectorF Speed, const char* Path) 
      : PhysicalEntity(Path), speed{Speed}  {
          id = "Projectile";
          setPos(position);
        
      }
      
      Projectile::~Projectile() {

      }

      void Projectile::update(float elapsedTime) {
        position += speed * elapsedTime;
      }

      void Projectile::initializeSpecific() {
        currentLevel->getGraphicsManager()->loadAsset(path);
        Utils::VectorF size = currentLevel->getGraphicsManager()->getSizeOfAsset(path);
        width = size.x;
        height = size.y;
      }

      void Projectile::collided(std::string other_id, Utils::VectorF positionOther, Utils::VectorF size) {
        destroySelf();
      }

      void Projectile::adjust() {

      }

      
      void Projectile::setSpeed(Utils::VectorF Speed) {
        speed = Speed;
      }

      void Projectile::destroySelf() {
        currentLevel->markForDelete(this);
        
      }
    }


  }
}