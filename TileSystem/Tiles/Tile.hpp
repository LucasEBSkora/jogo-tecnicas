#ifndef TILE_HPP
#define TILE_HPP

#include "../../Vector.hpp"
#include "../../GraphicsManager.hpp"

namespace DIM {

  class TileManager;

  class Tile {
  
  protected:
  
    const char* id;
    const char* path;
    VectorF size;

    GraphicsManager* graphicsManager;
    TileManager* parent;
  
  public:
    Tile(const char* Id = 0, const char* Path = 0, const VectorF Size = VectorF());
    ~Tile();

    virtual void collided(std::string id, VectorF positionOther, VectorU positionMine) = 0;
    virtual void initialize(GraphicsManager* graph, TileManager* Parent);
    virtual void draw(VectorF at) const;
    std::string getID() const;
  };
}

#endif