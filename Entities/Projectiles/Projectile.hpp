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
      Utility::VectorF speed;
      const char* path;

      void destroySelf();
    public:
      Projectile(Utility::VectorF position = Utility::VectorF(0.0f, 0.0f), Utility::VectorF Speed = Utility::VectorF(0.0f, 0.0f), const char* Path = nullptr);
      virtual ~Projectile();
      
      void setSpeed(Utility::VectorF Speed);

      void update(float elapsedTime) override;
      void draw() const override;
      void initializeSpecific() override;

      virtual void collided(std::string Id, Utility::VectorF positionOther, Utility::VectorF size) override;
      void adjust() override;

    };

  }
}

#endif