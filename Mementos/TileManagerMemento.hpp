#ifndef TILEMANAGERMEMENTO_HPP
#define TILEMANAGERMEMENTO_HPP

#include "Memento.hpp"
#include "../GeometricVector.hpp"
#include <vector>

namespace DIM {
  
  namespace Tile {
    class TileMap;
    class TileManager;
  }

  namespace Mementos {

    class TileManagerMemento : public Memento {
    private:
      TileManagerMemento();
      TileManagerMemento(Tile::TileMap& tilemap, Utility::VectorU playerSpawn, Utility::VectorU itemSpawn, Utility::VectorU bossSpawn, std::vector<Utility::VectorF> enSpawns);

      Utility::VectorU tilesSize;
      short** tiles;

      Utility::VectorU firstSpawnPointFound;
      Utility::VectorU firstItemSpawnPointFound;
      Utility::VectorU firstBossSpawnPointFound;
      std::vector<Utility::VectorF> enemySpawns;

      short getTileAt(unsigned i, unsigned j) const;
      Utility::VectorU getFirstSpawnPointFound() const;
      Utility::VectorU getFirstItemSpawnPointFound() const;
      Utility::VectorU getFirstBossSpawnPointFound() const;
      std::vector<Utility::VectorF> getEnemySpawns() const;

    public:
      TileManagerMemento(const TileManagerMemento& other);
      ~TileManagerMemento();

      void saveToFile(std::ostream& file) override;
      static TileManagerMemento loadFromFile(std::istream& file);
      friend class Tile::TileManager;
    };

  } 
}

#endif