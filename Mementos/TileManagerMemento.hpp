#ifndef TILEMANAGERMEMENTO_HPP
#define TILEMANAGERMEMENTO_HPP

#include "Memento.hpp"
#include "../Utils/GeometricVector.hpp"
#include <vector>

namespace DIM {
  
  namespace Tiles {
    class TileMap;
    class TileManager;
  }

  namespace Mementos {

    class TileManagerMemento : public Memento {
    private:

      Utils::VectorU tilesSize;
      short** tiles;

      Utils::VectorU firstSpawnPointFound;
      Utils::VectorU firstItemSpawnPointFound;
      Utils::VectorU firstBossSpawnPointFound;
      std::vector<Utils::VectorF> enemySpawns;

      TileManagerMemento();
      TileManagerMemento(Tiles::TileMap& tilemap, Utils::VectorU playerSpawn, Utils::VectorU itemSpawn, Utils::VectorU bossSpawn, std::vector<Utils::VectorF> enSpawns);

      short getTileAt(unsigned i, unsigned j) const;
      Utils::VectorU getFirstSpawnPointFound() const;
      Utils::VectorU getFirstItemSpawnPointFound() const;
      Utils::VectorU getFirstBossSpawnPointFound() const;
      std::vector<Utils::VectorF> getEnemySpawns() const;

    public:
      TileManagerMemento(const TileManagerMemento& other);
      ~TileManagerMemento();

      void saveToFile(std::ostream& file) override;
      static TileManagerMemento loadFromFile(std::istream& file);
      friend class Tiles::TileManager;
    };

  } 
}

#endif