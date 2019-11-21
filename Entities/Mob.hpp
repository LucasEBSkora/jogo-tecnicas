#ifndef MOB_HPP
#define MOB_HPP

#include "PhysicalEntity.hpp"

namespace DIM {

  namespace Levels {
    class Level;
  }
  
  namespace Entities {
    
    class Mob : public PhysicalEntity {
    protected:
      Utility::VectorF velocity;
    public:
      Mob();
      virtual ~Mob();
      
      void setPosition(Utility::VectorF pos);
    };

  }
}

#endif 