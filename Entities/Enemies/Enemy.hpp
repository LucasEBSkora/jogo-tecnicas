#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../Mob.hpp"

namespace DIM {

  class Enemy : public Mob {
  private:
    const std::string path;

  public:
    Enemy(const std::string path = "");
    virtual ~Enemy();
    
    virtual void draw() const override;
    virtual void initializeSpecific() override;
  };
}

#endif