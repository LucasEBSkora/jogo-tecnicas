#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "../Vector.hpp"

namespace DIM {
  
  class TileMap {
    
    private:
      VectorU tileMapSize;
      short **tileMap;
      const char *path;
    

    public:
      TileMap(const char* path = nullptr);
      ~TileMap();
      void loadTileMap(const char* path);
      const VectorU getSize() const;
      

      class TileMapLine {
        private:
          short* tileLine;
          unsigned int lineLenght;

        public:
          TileMapLine(short* line = nullptr, unsigned int lenght = 0);
          TileMapLine();
          const short operator[](unsigned int j) const;
      };
      
      const TileMapLine operator[](unsigned int i) const;
  };
}

#endif