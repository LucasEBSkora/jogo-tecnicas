#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../Mob.hpp"

namespace DIM {
  namespace Entities {
    namespace Mobs {

      class Enemy : public Mob {
      public:
        Enemy(const char* path = nullptr);
        virtual ~Enemy();
        
        virtual void initializeSpecific() override;
      };
    }

  }
}

#endif