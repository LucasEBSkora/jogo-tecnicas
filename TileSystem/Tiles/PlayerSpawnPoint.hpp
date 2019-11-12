#ifndef PLAYERSPAWNPOINT_HPP
#define PLAYERSPAWNPOINT_HPP

#include "Tile.hpp"

namespace DIM {
  class PlayerSpawnPoint : public Tile {
  private:

  public:
    PlayerSpawnPoint(const char *Path = "");
    ~PlayerSpawnPoint();
  };

}

#endif