#ifndef TILEMANAGER_HPP
#define TILEMANAGER_HPP

#include "Tile.hpp"
#include "TileVector.hpp"
#include <tuple>
#include "../Entities/Entity.hpp"
#include "../GeometricVector.hpp"
#include "TileMap.hpp"
#include "../Mementos/TileManagerMemento.hpp"

namespace DIM {

  namespace Levels {
    class Level;
  }

  namespace Tiles {
      
    enum PresetTiles {
      emptyTile = -1,
      forbbidenSpawn = -2,
    };
      
    typedef std::tuple<std::string, Utility::VectorF, Utility::VectorF> IdPositionSizeTuple;

    class TileManager : public Entities::Entity {
    private:
      TileVector tiles;
      float tileSide;
      Utility::VectorU firstSpawnPointFound;
      Utility::VectorU firstItemSpawnPointFound;
      Utility::VectorU firstBossSpawnPointFound;
      const char* path;
      TileMap& tileMap;
      void initializeSpecific() override;
      std::vector<Utility::VectorF> enemySpawns;

    public:
      TileManager( std::vector<Tile*> Tiles = std::vector<Tile*>(), float TileSide = 0.0f, const char* Path = nullptr);
      ~TileManager();

      std::vector<IdPositionSizeTuple> checkCollisions(Utility::VectorF at, Utility::VectorF size, std::string id);
      
      void update(float elapsedTime) override;
      void draw() const override;

      const TileMap* getTileMap() const;
      
      Utility::VectorF getWorldSize() const;
      Utility::VectorF getPlayerSpawnPosition() const;
      Utility::VectorF getItemSpawnPosition() const;
      Utility::VectorF getBossSpawnPosition() const;
      Levels::Level* getLevel() const;
      const std::vector<Utility::VectorF>& getEnemySpawns() const;

      void regenRandomTiles();

      Mementos::TileManagerMemento createMemento() const;
      void loadMemento(Mementos::TileManagerMemento memento);
    };

  }
}

#endif