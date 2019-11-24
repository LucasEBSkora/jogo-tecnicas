#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "../Utils/GeometricVector.hpp"

namespace DIM {
  namespace Tiles {
      
    class TileManager;
    
    class TileMap {
      
      private:
        Utils::VectorU tileMapSize;
        short** tileMap;
        const char* path;
        TileManager* manager;

      public:
        TileMap(const char* Path = nullptr, TileManager* man = nullptr);
        ~TileMap();
        void loadTileMap(const char* path);
        const Utils::VectorU getSize() const;
        void drawTileMap() const;
        TileManager* getTileManager() const;
        void setTileAt(unsigned i, unsigned j, short tile);

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
}


#endif