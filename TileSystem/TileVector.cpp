#include "TileVector.hpp"

namespace DIM {
  
  TileVector::TileVector(std::vector<Tile*> Tiles) : tiles{Tiles} {

  }

  TileVector::~TileVector() {
    for (Tile* t : tiles) {
      delete t;
    }

  }

  Tile* TileVector::operator[] (unsigned int index) const {
    return tiles[index];
  }

  void TileVector::initializeAll(GraphicsManager* graph, TileManager* tm) {
    for (Tile* t : tiles) {
      t->initialize(graph, tm);
    }
  }


} // namespace DIM