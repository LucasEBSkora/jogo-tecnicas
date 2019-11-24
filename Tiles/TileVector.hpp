#ifndef TILEVECTOR_HPP
#define TILEVECTOR_HPP

#include <vector>
#include "Tile.hpp"

namespace DIM {
  namespace Tiles {

    class TileVector {
    private:
      std::vector<Tile*> tiles;
    public:
      TileVector(std::vector<Tile*> Tiles = std::vector<Tile*>());
      ~TileVector();
      Tile* operator[](unsigned int index) const;
      void initializeAll(Managers::GraphicsManager* graph, TileManager* tm);

    };
  
  }
}


#endif