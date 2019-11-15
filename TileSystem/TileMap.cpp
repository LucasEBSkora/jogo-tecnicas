#include "TileMap.hpp"

#include <iostream>
#include <fstream>
#include "../RandomValueGenerator.hpp"

namespace DIM {

  TileMap::TileMap(const char* path) {
    if (path != nullptr) loadTileMap(path);
  }

  TileMap::~TileMap() {

    if (tileMap != nullptr) {
      for (unsigned i = 0; i < tileMapSize.y; ++i) delete []tileMap[i];
      delete []tileMap;
    }
  }

  void TileMap::loadTileMap(const char* Path) {
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

  TileMap::TileMapLine::TileMapLine(short* line, unsigned int lenght) : tileLine{line}, lineLenght{lenght} {

  }

  TileMap::TileMapLine::TileMapLine() {

  }

  const short TileMap::TileMapLine::operator[](unsigned int j) const {
    if (j < lineLenght) return tileLine[j];
    else {
      std::cout << "Warning! trying to access tile out of tileMap bounds" << std::endl;
      throw std::string("out of bounds");
    }

  }

  const TileMap::TileMapLine TileMap::operator[](unsigned int i) const {
    if (i < tileMapSize.y) return TileMapLine(tileMap[i], tileMapSize.x);
    else {
      std::cout << "Warning! trying to access tile out of bounds" << std::endl;
      throw std::string("out of bounds");
    }
  }

  const VectorU TileMap::getSize() const {
    return tileMapSize;
  }

}