#ifndef BulletOBSTACLE_HPP
#define BulletOBSTACLE_HPP

#include "../Tile.hpp"

namespace DIM {
  class BulletObstacle : public Tile {
  private:


  public:
    BulletObstacle();
    ~BulletObstacle();
    void collided(std::string id, VectorF positionOther, VectorU positionMine) override;
  };

}

#endif