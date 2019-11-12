#ifndef TILE_HPP
#define TILE_HPP

#include "../../Vector.hpp"
#include "../../GraphicsManager.hpp"

namespace DIM {

  class TileManager;

  class Tile {
  
  protected:
  
    const char* ID;
    const char* path;
    VectorF size;

    GraphicsManager* graphicsManager;
    TileManager* parent;
  
  public:
    Tile(const char* Id = nullptr, const char* Path = nullptr, const VectorF Size = VectorF(32.0f, 32.0f));
    virtual ~Tile();

    virtual void collided(std::string id, VectorF positionOther, VectorU positionMine);
    virtual void initialize(GraphicsManager* graph, TileManager* Parent);
    virtual void draw(VectorF at) const;
    std::string getID() const;
  };
}

#endif