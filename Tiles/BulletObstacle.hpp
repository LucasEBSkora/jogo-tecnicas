#ifndef BULLETOBSTACLE_HPP
#define BULLETOBSTACLE_HPP

#include "Tile.hpp"

namespace DIM {
  namespace Tiles {
      
    class BulletObstacle : public Tile {
    private:
      int delay;

    public:
      BulletObstacle();
      ~BulletObstacle();
      void collided(const std::string id, const Utils::VectorF positionOther, const Utils::VectorU positionMine) override;
    };

  }
}

#endif