#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "../PhysicalEntity.hpp"
#include "../../GeometricVector.hpp"
#include <string>


namespace DIM {
  
  namespace Levels {
    class Level;
  }

  namespace Entities {

    class Projectile : public PhysicalEntity {
    protected:
      Utils::VectorF speed;
      const char* path;

      void destroySelf();
    public:
      Projectile(Utils::VectorF position = Utils::VectorF(0.0f, 0.0f), Utils::VectorF Speed = Utils::VectorF(0.0f, 0.0f), const char* Path = nullptr);
      virtual ~Projectile();
      
      void setSpeed(Utils::VectorF Speed);

      void update(float elapsedTime) override;
      void draw() const override;
      void initializeSpecific() override;

      virtual void collided(std::string Id, Utils::VectorF positionOther, Utils::VectorF size) override;
      void adjust() override;

    };

  }
}

#endif