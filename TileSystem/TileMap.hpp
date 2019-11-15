#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "../Vector.hpp"

namespace DIM {
  class TileManager;
  
  class TileMap {
    
    private:
      VectorU tileMapSize;
      short **tileMap;
      const char *path;
      TileManager* manager;

    public:
      TileMap(const char* path = nullptr, TileManager* man = nullptr);
      ~TileMap();
      void loadTileMap(const char* path);
      const VectorU getSize() const;
      void drawTileMap() const;
      TileManager* getTileManager() const;

      class TileMapLine {
        private:
          short* tileLine;
          unsigned int lineLength;

        public:
          TileMapLine(short* line = nullptr, unsigned int length = 0);
          TileMapLine();
          const short operator[](unsigned int j) const;
      };
      
      const TileMapLine operator[](unsigned int i) const;
  };
}

#endif