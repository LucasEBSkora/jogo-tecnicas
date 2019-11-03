#include "Entity.hpp"

namespace HE {

  Entity::Entity(const char* Path, sf::Vector2f Position, sf::Vector2i TexturePosition, bool FacingRight) : 
    path{Path},
    position{Position},
    texturePosition{TexturePosition},
    facingRight{FacingRight} {
      
    }

  Entity::~Entity() {

  }

  const sf::Vector2f Entity::getPosition() const {
    return position;
  }

  const sf::Vector2i Entity::getTexturePosition() const {
    return texturePosition;
  }

  const char* Entity::getAssetPath() const {
    return path;
  }

  bool Entity::isFacingRight() const {
    return facingRight;
  }

  void Entity::init(EventListeners* l) {
    listener = l;
    subscribe();
  }
}