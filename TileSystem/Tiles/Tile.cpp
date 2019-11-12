#include "Tile.hpp"

#include "../TileManager.hpp"

namespace DIM {
    Tile::Tile(const char* Id, const char* Path, const VectorF Size) : id{Id}, path{Path}, size{Size} {

    }

    Tile::~Tile() {

    }

    void Tile::initialize(GraphicsManager* graph, TileManager* Parent) {
      graphicsManager = graph;
      parent = Parent;

      graph->loadAsset(path);
    }

    void Tile::draw(const VectorF at) const {
      graphicsManager->draw(path, at);
    }

    std::string Tile::getID() const {
      return id;
    }

    void Tile::collided(std::string id, VectorF positionOther, VectorU positionMine) {
      //Default behavior is to ignore collisions
    }

  
}