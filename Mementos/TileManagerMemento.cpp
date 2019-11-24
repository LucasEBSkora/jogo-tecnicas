#include "TileManagerMemento.hpp"
#include "../Tiles/TileMap.hpp"

namespace DIM {
  namespace Mementos {
  
    TileManagerMemento::TileManagerMemento() : tilesSize(0, 0), tiles(nullptr),
      firstSpawnPointFound(0, 0), enemySpawns() {

    }
    
    TileManagerMemento::TileManagerMemento(Tiles::TileMap& tilemap, Utils::VectorU playerSpawn, Utils::VectorU itemSpawn, Utils::VectorU bossSpawn, std::vector<Utils::VectorF> enSpawns) {
      tilesSize = tilemap.getSize();
      tiles = new short*[tilesSize.y];
      for (unsigned i = 0; i < tilesSize.y; ++i) {
        tiles[i] = new short[tilesSize.x];
      }
      for (unsigned i = 0; i < tilesSize.y; ++i) {
        for (unsigned j = 0; j < tilesSize.x; ++j) {
          tiles[i][j] = tilemap[i][j];
        }
      }
      firstSpawnPointFound = playerSpawn;
      firstItemSpawnPointFound = itemSpawn;
      firstBossSpawnPointFound = bossSpawn;
      enemySpawns = enSpawns;
    }
    
    TileManagerMemento::TileManagerMemento(const TileManagerMemento& other) {
      tilesSize = other.tilesSize;
      tiles = new short*[tilesSize.y];
      for (unsigned i = 0; i < tilesSize.y; ++i) {
        tiles[i] = new short[tilesSize.x];
        for (unsigned j = 0; j < tilesSize.x; ++j) {
          tiles[i][j] = other.tiles[i][j];
        }
      }
      firstSpawnPointFound = other.firstSpawnPointFound;
      firstItemSpawnPointFound = other.firstItemSpawnPointFound;
      firstBossSpawnPointFound = other.firstBossSpawnPointFound;
      enemySpawns = other.enemySpawns;
    }

    short TileManagerMemento::getTileAt(unsigned i, unsigned j) const {
      return tiles[i][j];
    }

    Utils::VectorU TileManagerMemento::getFirstSpawnPointFound() const {
      return firstSpawnPointFound;
    }

    Utils::VectorU TileManagerMemento::getFirstItemSpawnPointFound() const {
      return firstItemSpawnPointFound;
    }

    Utils::VectorU TileManagerMemento::getFirstBossSpawnPointFound() const {
      return firstBossSpawnPointFound;
    }

    std::vector<Utils::VectorF> TileManagerMemento::getEnemySpawns() const {
      return enemySpawns;
    }
    
    TileManagerMemento::~TileManagerMemento() {
      for (unsigned i = 0; i < tilesSize.y; ++i) {
        delete[] tiles[i];
      }
      delete[] tiles;
    }

    void TileManagerMemento::saveToFile(std::ostream& file) {
      file << tilesSize.x << ' ' << tilesSize.y;
      for (unsigned i = 0; i < tilesSize.y; ++i) {
        for (unsigned j = 0; j < tilesSize.x; ++j) {
          file << ' ' << tiles[i][j];
        }
      }
      file << ' ' << firstSpawnPointFound.x << ' ' << firstSpawnPointFound.y;
      file << ' ' << firstItemSpawnPointFound.x << ' ' << firstItemSpawnPointFound.y;
      file << ' ' << firstBossSpawnPointFound.x << ' ' << firstBossSpawnPointFound.y;
      file << ' ' << enemySpawns.size();
      for (unsigned i = 0; i < enemySpawns.size(); ++i) {
        file << ' ' << enemySpawns[i].x << ' ' << enemySpawns[i].y;
      }
      file << '\n';
    }

    TileManagerMemento TileManagerMemento::loadFromFile(std::istream& file) {
      TileManagerMemento memento;
      file >> memento.tilesSize.x >> memento.tilesSize.y;
      memento.tiles = new short*[memento.tilesSize.y];
      for (unsigned i = 0; i < memento.tilesSize.y; ++i) {
        memento.tiles[i] = new short[memento.tilesSize.x];
        for (unsigned j = 0; j < memento.tilesSize.x; ++j) {
          file >> memento.tiles[i][j];
        }
      }
      file >> memento.firstSpawnPointFound.x >> memento.firstSpawnPointFound.y;
      file >> memento.firstItemSpawnPointFound.x >> memento.firstItemSpawnPointFound.y;
      file >> memento.firstBossSpawnPointFound.x >> memento.firstBossSpawnPointFound.y;
      int spawnsNumber = 0;
      file >> spawnsNumber;
      memento.enemySpawns.resize(spawnsNumber);
      for (unsigned i = 0; i < memento.enemySpawns.size(); ++i) {
        file >> memento.enemySpawns[i].x >> memento.enemySpawns[i].y;
      }
      return memento;
    }

  }
}