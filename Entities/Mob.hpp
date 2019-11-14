#ifndef MOB_HPP
#define MOB_HPP

#include "PhysicalEntity.hpp"

namespace DIM {
  class Level;
  
  class Mob : public PhysicalEntity {
  protected:
    float vx;
    float vy;
    Level* current_level;
  public:
    Mob();
    virtual ~Mob();
    
    void setPosition(VectorF pos);
    // VectorF getPosition() const;

    void setLevel(Level* level);
    Level* getLevel() const;
  };

}

#endif 