#include "Tile.hpp"

#include <iostream>
#include "../../GraphicsManager.hpp"

namespace DIM {
    Tile::Tile(const char* Id, const char* Path, const VectorF Size) : ID{Id}, path{Path}, size{Size} {

    }

    Tile::~Tile() {

    }

    void Tile::initialize(GraphicsManager* graph, TileManager* Parent) {
      graphicsManager = graph;
      parent = Parent;

      graphicsManager->loadAsset(path);
    }


    void Tile::draw(const VectorF at) const {
      if (graphicsManager == nullptr) {
        std::cout << "nao encontrado" << std::endl;
      }
      graphicsManager->draw(path, at);
    }

    std::string Tile::getID() const {
      return ID;
    }

    void Tile::collided(std::string id, VectorF positionOther, VectorU positionMine) {
      //Default behavior is to ignore collisions
    }

  
}