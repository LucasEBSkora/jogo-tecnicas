#ifndef TILEMANAGERMEMENTO_HPP
#define TILEMANAGERMEMENTO_HPP

#include "Memento.hpp"
// #include "../TileSystem/TileMap.hpp"
#include "../Vector.hpp"
#include <vector>

namespace DIM
{
  class TileMap;
  
  class TileManagerMemento : public Memento {
  private:
    TileManagerMemento();
    TileManagerMemento(TileMap& tilemap, VectorU playerSpawn, VectorU itemSpawn, VectorU bossSpawn, std::vector<VectorF> enSpawns);

    VectorU tilesSize;
    short** tiles;

    VectorU firstSpawnPointFound;
    VectorU firstItemSpawnPointFound;
    VectorU firstBossSpawnPointFound;
    std::vector<VectorF> enemySpawns;

    short getTileAt(unsigned i, unsigned j) const;
    VectorU getFirstSpawnPointFound() const;
    VectorU getFirstItemSpawnPointFound() const;
    VectorU getFirstBossSpawnPointFound() const;
    std::vector<VectorF> getEnemySpawns() const;

  public:
    ~TileManagerMemento();

    void saveToFile(std::ostream& file) override;
    static TileManagerMemento loadFromFile(std::istream& file);
    friend class TileManager;
  };
  
} // namespace DIM

#endif