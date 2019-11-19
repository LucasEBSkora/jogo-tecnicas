#include "TileManagerMemento.hpp"
#include "../TileSystem/TileMap.hpp"

namespace DIM {
  
  TileManagerMemento::TileManagerMemento() : tilesSize(0, 0), tiles(nullptr),
    firstSpawnPointFound(0, 0), enemySpawns() {

  }
  
  TileManagerMemento::TileManagerMemento(TileMap& tilemap, VectorU playerSpawn, std::vector<VectorF> enSpawns) {
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
    enemySpawns = other.enemySpawns;
  }

  short TileManagerMemento::getTileAt(unsigned i, unsigned j) const {
    return tiles[i][j];
  }

  VectorU TileManagerMemento::getFirstSpawnPointFound() const {
    return firstSpawnPointFound;
  }

  std::vector<VectorF> TileManagerMemento::getEnemySpawns() const {
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
    int spawnsNumber = 0;
    file >> spawnsNumber;
    memento.enemySpawns.resize(spawnsNumber);
    for (unsigned i = 0; i < memento.enemySpawns.size(); ++i) {
      file >> memento.enemySpawns[i].x >> memento.enemySpawns[i].y;
    }
    return memento;
  }

}