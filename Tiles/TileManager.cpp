#include "TileManager.hpp"

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "../RandomValueGenerator.hpp"
#include "../Levels/Level.hpp"

namespace DIM {
  namespace Tiles {

    TileManager::TileManager( std::vector<Tile*> Tiles, float TileSide, const char *Path) 
    : Entities::Entity(), tiles{Tiles}, tileSide{TileSide}, firstSpawnPointFound{0, 0}, firstItemSpawnPointFound{0,0},
    firstBossSpawnPointFound{0, 0}, path{Path}, tileMap{*(new TileMap(path, this))}
      {

    }

    TileManager::~TileManager() {
      delete &tileMap;
    }

    void TileManager::initializeSpecific() {
      tiles.initializeAll(currentLevel->getGraphicsManager(), this);
    }

    std::vector<IdPositionSizeTuple> TileManager::checkCollisions(Utility::VectorF at, Utility::VectorF size, std::string id) {

      Utility::VectorF op(at + size);

      Utility::VectorU start(static_cast<unsigned int>(floor(at.x/tileSide)), static_cast<unsigned int>(floor(at.y/tileSide)));
      
      Utility::VectorU end(static_cast<unsigned int>(floor(op.x/tileSide)), static_cast<unsigned int>(floor(op.y/tileSide)));
      
      std::vector<IdPositionSizeTuple> vec;

      if (at.x < 0 || at.y < 0 || end.x >= tileMap.getSize().x || end.y >= tileMap.getSize().y) {
        // std::cout << "Error! entity out of map bounds" << std::endl;
      } else {

        for (unsigned i = start.y; i <= end.y; ++i) {
          for (unsigned j = start.x; j <= end.x; ++j) {
            short tileId = tileMap[i][j];
            if (tileId >= 0) {
              
              vec.push_back( IdPositionSizeTuple(tiles[tileId]->getID(), Utility::VectorF(j*tileSide, i*tileSide), Utility::VectorF(tileSide, tileSide)));
              tiles[tileId]->collided(id, at, Utility::VectorU(i,j));
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
          if (tileMap[i][j] >= 0) tiles[tileMap[i][j]]->draw(Utility::VectorF((j)*tileSide, (i)*tileSide));
        }
      }
    }

    Utility::VectorF TileManager::getWorldSize() const {
      return Utility::VectorF(tileMap.getSize().x, tileMap.getSize().y) * tileSide;
    }

    Utility::VectorF TileManager::getPlayerSpawnPosition() const {
      
      return Utility::VectorF(firstSpawnPointFound.x, firstSpawnPointFound.y) * tileSide + Utility::VectorF(32.0f, 32.0f) * .5;
    }

    Utility::VectorF TileManager::getItemSpawnPosition() const {
      
      return Utility::VectorF(firstItemSpawnPointFound.x, firstItemSpawnPointFound.y) * tileSide + Utility::VectorF(32.0f, 32.0f) * .5;
    }

    Utility::VectorF TileManager::getBossSpawnPosition() const {
      
      return Utility::VectorF(firstBossSpawnPointFound.x, firstBossSpawnPointFound.y) * tileSide + Utility::VectorF(32.0f, 32.0f) * .5;
    }

    Levels::Level* TileManager::getLevel() const {
      return currentLevel;
    }

    const TileMap* TileManager::getTileMap() const {
      return &tileMap;
    }

    const std::vector<Utility::VectorF>& TileManager::getEnemySpawns() const {
      return enemySpawns;
    }

    void TileManager::regenRandomTiles() {
      tileMap.loadTileMap(path);

      for (unsigned i = 0; i < tileMap.getSize().y; ++i) {
        for (unsigned j = 0; j < tileMap.getSize().x; ++j) {
          
          if (tileMap[i][j] == 1 && tileMap[i-1][j] < 0) {
            // found spawn point
            firstSpawnPointFound = Utility::VectorU(j, i - 1);
          } 

          if (tileMap[i][j] == -3) firstItemSpawnPointFound = Utility::VectorU(j, i);

          if (tileMap[i][j] == -4) firstBossSpawnPointFound = Utility::VectorU(j, i);

          if (i > 0 && tileMap[i][j] == 0 && tileMap[i-1][j] == -1) {
            // enemy spawn point
            enemySpawns.push_back(Utility::VectorF(j, i - 1) * tileSide);
          }  
        }
      }
    }

    Mementos::TileManagerMemento TileManager::createMemento() const {
      Mementos::TileManagerMemento memento(tileMap, firstSpawnPointFound, firstItemSpawnPointFound, firstBossSpawnPointFound, enemySpawns);
      return memento;
    }

    void TileManager::loadMemento(Mementos::TileManagerMemento memento) {
      for (unsigned i = 0; i < tileMap.getSize().y; ++i) {
        for (unsigned j = 0; j < tileMap.getSize().x; ++j) {
          tileMap.setTileAt(i, j, memento.getTileAt(i, j));
        }
      }
      firstSpawnPointFound = memento.getFirstSpawnPointFound();
      firstItemSpawnPointFound = memento.getFirstItemSpawnPointFound();
      firstBossSpawnPointFound = memento.getFirstBossSpawnPointFound();
      enemySpawns = memento.getEnemySpawns();
    }

  }
}