#ifndef BulletOBSTACLE_HPP
#define BulletOBSTACLE_HPP

#include "../Tile.hpp"

namespace DIM {
  class BulletObstacle : public Tile {
  private:


  public:
    BulletObstacle();
    ~BulletObstacle();
    void collided(const std::string id, const VectorF positionOther, const VectorU positionMine) override;
  };

}

#endif