#include "TileManager.hpp"

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "../RandomValueGenerator.hpp"

namespace DIM
{

  TileManager::TileManager( std::vector<Tile> Tiles, float TileSide, const char *Path) 
  : tiles{Tiles}, tileSide{TileSide}, tileMap{nullptr}, path{Path} {

    if (path != nullptr) loadTileMap(path);

  }

  TileManager::~TileManager() {
    if (tileMap != nullptr) {
      for (unsigned i = 0; i < tileMapSize.y; ++i) delete []tileMap[i];
      delete []tileMap;
    }

  }

  void TileManager::initializeSpecific() {
    
    for (Tile& t : tiles) {
      t.initialize(graphics_manager, this);
    }
  }


  void TileManager::loadTileMap(const char* Path) {
    path = Path;
    std::ifstream file;

    file.open(path);
    
    if (!file.is_open()) return;

    file >> tileMapSize.x >> tileMapSize.y; 
    tileMap = new short*[tileMapSize.y];
    
    for (unsigned i = 0; i < tileMapSize.y;++i)
      tileMap[i] = new short[tileMapSize.x];


    for (unsigned i = 0; i < tileMapSize.y; ++i) {
      if (file.eof()) {
        std::cout << "unexpected end of file while reading tileMap!" << std::endl;
        break;
      }
      for (unsigned j = 0; j < tileMapSize.x;) {
        
        if (file.eof()) break;
        
        if (file.peek() == ' ' || file.peek() == '\n') file.get(); //ignores spaces and line ends
        else if (file.peek() == '?') { //Random tile 
          
          file.get();

          short first, second; //gets the possible tile values

          file >> first >> second;

          tileMap[i][j] = (RandomValueGenerator::getInstance()->getRandomBool(50)) ? first : second; //50% chance of being the first, 50% of being the second
        
          ++j;
        } else if (('0' <= file.peek() && file.peek() <= '9') || file.peek() == '-') { //if it is a normal number, just saves it in the matrix
          
          file >> tileMap[i][j];
          if (tileMap[i][j] == 1 && tileMap[i-1][j] == -1) {
            // found spawn point
            firstSpawnPointFound = VectorU(j, i - 1);
          }
          ++j;
        
        } else { //if it is a weird character, prints it out
         std::cout << "\tunexpected character while loading tilemap: " << static_cast<char>(file.peek()) << std::endl;
        }

      }
    }
    std::cout << "ue " << tileMapSize.x << ' ' << tileMapSize.y << std::endl;


    for (unsigned i = 0; i < tileMapSize.y; ++i) {
      for (unsigned j = 0; j < tileMapSize.x; ++j) {
        std::cout << tileMap[i][j] << ' ';
        std::cout.flush();
      }
      std::cout << std::endl;
    }    

    file.close();

  }

  std::vector<IdPositionPair> TileManager::checkCollisions(VectorF at, VectorF size, std::string id) {

    VectorF op(at + size);

    VectorU start(static_cast<unsigned int>(floor(at.x/tileSide)), static_cast<unsigned int>(floor(at.y/tileSide)));
    // VectorU end(static_cast<unsigned int>(ceil(at.x/tileSide)), static_cast<unsigned int>(ceil(at.y/tileSide)));
    VectorU end(static_cast<unsigned int>(floor(op.x/tileSide)), static_cast<unsigned int>(floor(op.y/tileSide)));
    // std::cout << start.x << ' ' << start.y << ' ' << end.x << ' ' << end.y << std::endl;
    std::vector<IdPositionPair> vec;

    // unsigned pode ter dado a volta
    if (start.x >= tileMapSize.x || start.y >= tileMapSize.y || end.x >= tileMapSize.x || end.y >= tileMapSize.y) {
      std::cout << "Error! entity out of map bounds" << std::endl;
    } else {

      for (unsigned i = start.y; i <= end.y; ++i) {
        for (unsigned j = start.x; j <= end.x; ++j) {
          short tileId = tileMap[i][j];
          if (tileId >= 0) {

            vec.push_back( IdPositionPair(tiles[tileId].getID(), VectorF((i + 0.5)*tileSide, (j + 0.5)*tileSide)));
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
    
    for (unsigned i = 0; i < tileMapSize.y; ++i) {
      for (unsigned j = 0; j < tileMapSize.x; ++j) {
        if (tileMap[i][j] >= 0) tiles[tileMap[i][j]].draw(VectorF((j)*tileSide, (i)*tileSide));
      }
    }
  }

  VectorF TileManager::getWorldSize() const {
    return VectorF(tileMapSize.x, tileMapSize.y) * tileSide;
  }

  VectorF TileManager::getPlayerSpawnPosition() const {
    return VectorF(firstSpawnPointFound.x, firstSpawnPointFound.y) * tileSide;
  }

} // namespace DIM
