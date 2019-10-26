#include "Model.hpp"

namespace FISW {

  Model::Model(const char* Path, sf::Vector2f Position, sf::Vector2i TexturePosition, bool FacingRight) : 
    path{Path},
    position{Position},
    texturePosition{TexturePosition},
    facingRight{FacingRight} {
      
    }

  Model::~Model() {

  }

  const sf::Vector2f Model::getPosition() const {
    return position;
  }

  const sf::Vector2i Model::getTexturePosition() const {
    return texturePosition;
  }

  const char* Model::getAssetPath() const {
    return path;
  }

  bool Model::isFacingRight() const {
    return facingRight;
  }

  void Model::init(EventListeners* l) {
    listener = l;
    subscribe();
  }
}