#ifndef WALLTILE_HPP
#define WALLTILE_HPP

#include "Tile.hpp"

namespace DIM {
  namespace Tile {

    class WallTile : public Tile {
    private:

    public:
      WallTile(const char* Path = "");
      virtual ~WallTile();
    };

  }
}

#endif