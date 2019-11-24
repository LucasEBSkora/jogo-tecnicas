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
      
    typedef std::tuple<std::string, Utils::VectorF, Utils::VectorF> IdPositionSizeTuple;

    class TileManager : public Entities::Entity {
    private:
      TileVector tiles;
      float tileSide;
      Utils::VectorU firstSpawnPointFound;
      Utils::VectorU firstItemSpawnPointFound;
      Utils::VectorU firstBossSpawnPointFound;
      const char* path;
      TileMap& tileMap;
      void initializeSpecific() override;
      std::vector<Utils::VectorF> enemySpawns;

    public:
      TileManager( std::vector<Tile*> Tiles = std::vector<Tile*>(), float TileSide = 0.0f, const char* Path = nullptr);
      ~TileManager();

      std::vector<IdPositionSizeTuple> checkCollisions(Utils::VectorF at, Utils::VectorF size, std::string id);
      
      void update(float elapsedTime) override;
      void draw() const override;

      const TileMap* getTileMap() const;
      
      Utils::VectorF getWorldSize() const;
      Utils::VectorF getPlayerSpawnPosition() const;
      Utils::VectorF getItemSpawnPosition() const;
      Utils::VectorF getBossSpawnPosition() const;
      Levels::Level* getLevel() const;
      const std::vector<Utils::VectorF>& getEnemySpawns() const;

      void regenRandomTiles();

      Mementos::TileManagerMemento createMemento() const;
      void loadMemento(Mementos::TileManagerMemento memento);
    };

  }
}

#endif