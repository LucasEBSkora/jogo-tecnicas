#include "TileManager.hpp"

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "../RandomValueGenerator.hpp"
#include "../Levels/Level.hpp"

namespace DIM
{

  TileManager::TileManager( std::vector<Tile*> Tiles, float TileSide, const char *Path) 
  : Entity(), tiles{Tiles}, tileSide{TileSide}, firstSpawnPointFound{0, 0}, firstItemSpawnPointFound{0,0},
  firstBossSpawnPointFound{0, 0}, path{Path}, tileMap{*(new TileMap(path, this))}
     {

  }

  TileManager::~TileManager() {
    delete &tileMap;
    
    for (Tile* t : tiles) {
      delete t;
    }
  }

  void TileManager::initializeSpecific() {
    
    for (Tile* t : tiles) {
      t->initialize(currentLevel->getGraphicsManager(), this);
    }

    for (unsigned i = 0; i < tileMap.getSize().y; ++i) {
      for (unsigned j = 0; j < tileMap.getSize().x; ++j) {
        
        if (tileMap[i][j] == 1 && tileMap[i-1][j] < 0) {
          // found spawn point
          
          firstSpawnPointFound = VectorU(j, i - 1);
          // jeito talvez mais certo (menos errado): tiles[tileMap[i][j]].isPlayerSpawnPoint()
        } 

        if (tileMap[i][j] == -3) firstItemSpawnPointFound = VectorU(j, i);

        if (tileMap[i][j] == -4) firstBossSpawnPointFound = VectorU(j, i);

        if (i > 0 && tileMap[i][j] == 0 && tileMap[i-1][j] == -1) {
          // enemy spawn point
          // arrumar depois
          enemySpawns.push_back(VectorF(j, i - 1) * tileSide);
        }
      
      }
    }
  }

  std::vector<IdPositionSizeTuple> TileManager::checkCollisions(VectorF at, VectorF size, std::string id) {

    VectorF op(at + size);

    VectorU start(static_cast<unsigned int>(floor(at.x/tileSide)), static_cast<unsigned int>(floor(at.y/tileSide)));
    // VectorU end(static_cast<unsigned int>(ceil(at.x/tileSide)), static_cast<unsigned int>(ceil(at.y/tileSide)));
    VectorU end(static_cast<unsigned int>(floor(op.x/tileSide)), static_cast<unsigned int>(floor(op.y/tileSide)));
    // std::cout << start.x << ' ' << start.y << ' ' << end.x << ' ' << end.y << std::endl;
    std::vector<IdPositionSizeTuple> vec;

    if (at.x < 0 || at.y < 0 || end.x >= tileMap.getSize().x || end.y >= tileMap.getSize().y) {
      // std::cout << "Error! entity out of map bounds" << std::endl;
    } else {

      for (unsigned i = start.y; i <= end.y; ++i) {
        for (unsigned j = start.x; j <= end.x; ++j) {
          short tileId = tileMap[i][j];
          if (tileId >= 0) {
            
            // std::cout << tileId << std::endl;
            vec.push_back( IdPositionSizeTuple(tiles[tileId]->getID(), VectorF(j*tileSide, i*tileSide), VectorF(tileSide, tileSide)));
            tiles[tileId]->collided(id, at, VectorU(i,j));
          }
        }
      }
    }

    return vec;
  }

  void TileManager::update(float elapsedTime) {
    // needs the function because it extends entity, but it doesn't actually need to update

  }

  void TileManager::draw() const {
    for (unsigned i = 0; i < tileMap.getSize().y; ++i) {
      for (unsigned j = 0; j < tileMap.getSize().x; ++j) {
        if (tileMap[i][j] >= 0) tiles[tileMap[i][j]]->draw(VectorF((j)*tileSide, (i)*tileSide));
      }
    }
  }

  VectorF TileManager::getWorldSize() const {
    return VectorF(tileMap.getSize().x, tileMap.getSize().y) * tileSide;
  }

  VectorF TileManager::getPlayerSpawnPosition() const {
    
    return VectorF(firstSpawnPointFound.x, firstSpawnPointFound.y) * tileSide + VectorF(32.0f, 32.0f) * .5;
  }

  VectorF TileManager::getItemSpawnPosition() const {
    
    return VectorF(firstItemSpawnPointFound.x, firstItemSpawnPointFound.y) * tileSide + VectorF(32.0f, 32.0f) * .5;
  }

  VectorF TileManager::getBossSpawnPosition() const {
    
    return VectorF(firstItemSpawnPointFound.x, firstItemSpawnPointFound.y) * tileSide + VectorF(32.0f, 32.0f) * .5;
  }

  Level* TileManager::getLevel() const {
    return currentLevel;
  }

  const TileMap* TileManager::getTileMap() const {
    return &tileMap;
  }

  const std::vector<VectorF>& TileManager::getEnemySpawns() const {
    return enemySpawns;
  }

} // namespace DIM