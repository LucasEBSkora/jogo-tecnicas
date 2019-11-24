#include "Tile.hpp"

#include <iostream>
#include "../../Managers/GraphicsManager.hpp"

namespace DIM {
  namespace Tiles {

    Tile::Tile(const char* Id, const char* Path, const Utils::VectorF Size) : ID{Id}, path{Path}, size{Size} {

    }

    Tile::~Tile() {

    }

    void Tile::initialize(Managers::GraphicsManager* graph, TileManager* Parent) {
      graphicsManager = graph;
      parent = Parent;

      graphicsManager->loadAsset(path);
    }


    void Tile::draw(const Utils::VectorF at) const {
      if (graphicsManager == nullptr) {
        std::cout << "nao encontrado" << std::endl;
      }
      graphicsManager->draw(path, at);
    }

    const std::string Tile::getID() const {
      return ID;
    }

    void Tile::collided(const std::string id, const Utils::VectorF positionOther, const Utils::VectorU positionMine) {
      //Default behavior is to ignore collisions
    }

  }
}