#ifndef MOB_HPP
#define MOB_HPP

#include "PhysicalEntity.hpp"

namespace DIM {

  namespace Levels {
    class Level;
  }
  
  namespace Entities {

    namespace Mobs {

      class Mob : public PhysicalEntity {
      protected:
        Utils::VectorF velocity;
      public:
        Mob(const char* path = nullptr);
        virtual ~Mob();
        
        void setPosition(Utils::VectorF pos);
      };

    }
    

  }
}

#endif 