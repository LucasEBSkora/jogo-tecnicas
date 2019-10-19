#include "Model.h"

namespace FISW {

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
}