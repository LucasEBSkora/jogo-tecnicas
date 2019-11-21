#ifndef TILE_HPP
#define TILE_HPP

#include "../../GeometricVector.hpp"
#include "../../GraphicsManager.hpp"

namespace DIM {
  namespace Tile {

    class TileManager;

    class Tile {
    protected:
    
      const char* ID;
      const char* path;
      Utility::VectorF size;

      Managers::GraphicsManager* graphicsManager;
      TileManager* parent;
    
    public:
      Tile(const char* Id = nullptr, const char* Path = nullptr, const Utility::VectorF Size = Utility::VectorF(32.0f, 32.0f));
      virtual ~Tile();

      virtual void collided(const std::string id, const Utility::VectorF positionOther, const Utility::VectorU positionMine);
      virtual void initialize(Managers::GraphicsManager* graph, TileManager* Parent);
      virtual void draw(Utility::VectorF at) const;
      const std::string getID() const;
    };

  }
}

#endif