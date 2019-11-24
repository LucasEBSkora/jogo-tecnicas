#ifndef TILE_HPP
#define TILE_HPP

#include "../GeometricVector.hpp"
#include "../GraphicsManager.hpp"

namespace DIM {
  namespace Tiles {

    class TileManager;

    class Tile {
    protected:
    
      const char* ID;
      const char* path;
      Utils::VectorF size;

      Managers::GraphicsManager* graphicsManager;
      TileManager* parent;
    
    public:
      Tile(const char* Id = nullptr, const char* Path = nullptr, const Utils::VectorF Size = Utils::VectorF(32.0f, 32.0f));
      virtual ~Tile();

      virtual void collided(const std::string id, const Utils::VectorF positionOther, const Utils::VectorU positionMine);
      virtual void initialize(Managers::GraphicsManager* graph, TileManager* Parent);
      virtual void draw(Utils::VectorF at) const;
      const std::string getID() const;
    };

  }
}

#endif