#ifndef TILEMANAGER_HPP
#define TILEMANAGER_HPP

#include "Tiles/Tile.hpp"
#include <vector>
#include <tuple>
#include "../Entities/Entity.hpp"
#include "../Vector.hpp"
#include "TileMap.hpp"
#include "../Mementos/TileManagerMemento.hpp"

namespace DIM {
  class Level;

  enum PresetTiles {
    emptyTile = -1,
    forbbidenSpawn = -2,
  };
    
  typedef std::tuple<std::string, VectorF, VectorF> IdPositionSizeTuple;

  class TileManager : public Entity {
  private:
    std::vector<Tile*> tiles;
    float tileSide;
    VectorU firstSpawnPointFound;
    const char* path;
    TileMap& tileMap;
    void initializeSpecific() override;
    std::vector<VectorF> enemySpawns;

  public:

    

    TileManager( std::vector<Tile*> Tiles = std::vector<Tile*>(), float TileSide = 0.0f, const char *Path = nullptr);
    ~TileManager();

    

    std::vector<IdPositionSizeTuple> checkCollisions(VectorF at, VectorF size, std::string id);
    
    void update(float elapsedTime) override;
    void draw() const override;

    const TileMap* getTileMap() const;
    
    VectorF getWorldSize() const;
    VectorF getPlayerSpawnPosition() const;
    Level* getLevel() const;
    const std::vector<VectorF>& getEnemySpawns() const;

    TileManagerMemento createMemento() const;
    void loadMemento(TileManagerMemento memento);
  };
}

#endif