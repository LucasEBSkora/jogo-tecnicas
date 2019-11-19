#ifndef TILEVECTOR_HPP
#define TILEVECTOR_HPP

#include <vector>
#include "Tiles/Tile.hpp"

namespace DIM {

  class TileVector {
    private:
      std::vector<Tile*> tiles;
    public:
      TileVector(std::vector<Tile*> Tiles = std::vector<Tile*>());
      ~TileVector();
      Tile* operator[](unsigned int index) const;
      void initializeAll(GraphicsManager* graph, TileManager* tm);

  };
  
} // namespace DIM


#endif