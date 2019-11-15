#ifndef TILEMANAGER_HPP
#define TILEMANAGER_HPP

#include "Tiles/Tile.hpp"
#include <vector>
#include "../Entities/Entity.hpp"
#include "../Vector.hpp"
#include "TileMap.hpp"

namespace DIM {

  enum PresetTiles {
    emptyTile = -1,
    forbbidenSpawn = -2,
  };
    
  typedef std::pair<std::string, VectorF> IdPositionPair;

  class TileManager : public Entity {
  private:
    std::vector<Tile> tiles;
    float tileSide;
    VectorU firstSpawnPointFound;
    const char* path;
    TileMap& tileMap;
    void initializeSpecific() override;

  public:

    

    TileManager( std::vector<Tile> Tiles = std::vector<Tile>(), float TileSide = 0.0f, const char *Path = nullptr);
    ~TileManager();

    

    std::vector<IdPositionPair> checkCollisions(VectorF at, VectorF size, std::string id);
    
    void update(float elapsedTime) override;
    void draw() const override;
    
    VectorF getWorldSize() const;
    VectorF getPlayerSpawnPosition() const;
  };
}

#endif