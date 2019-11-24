#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "../PhysicalEntity.hpp"
#include "../../Utils/GeometricVector.hpp"
#include <string>


namespace DIM {
  
  namespace Levels {
    class Level;
  }

  namespace Entities {
    namespace Projectiles {

      class Projectile : public PhysicalEntity {
      protected:
        Utils::VectorF speed;

        void destroySelf();
      public:
        Projectile(Utils::VectorF position = Utils::VectorF(0.0f, 0.0f), Utils::VectorF Speed = Utils::VectorF(0.0f, 0.0f), const char* Path = nullptr);
        virtual ~Projectile();
        
        void setSpeed(Utils::VectorF Speed);

        void update(float elapsedTime) override;
        void initializeSpecific() override;

        virtual void collided(std::string Id, Utils::VectorF positionOther, Utils::VectorF size) override;
        void adjust() override;

      };
    }


  }
}

#endif