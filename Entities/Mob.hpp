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
      Utils::VectorF velocity;
    public:
      Mob();
      virtual ~Mob();
      
      void setPosition(Utils::VectorF pos);
    };

  }
}

#endif 