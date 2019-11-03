#include "EntityDrawable.hpp"
#include "Entity.hpp"

#include <iostream>

namespace HE {

EntityDrawable::EntityDrawable(const char* Path, sf::Vector2f Size, const Entity* Entity, sf::Vector2i numberFrames) :
  path{Path},
  size{Size},
  frames{numberFrames},
  entity{Entity},
  box{Size} {

  box.setPosition(entity->getPosition());
}

EntityDrawable::~EntityDrawable() {
}

// Finds the asset in the map using the path as a key, returns 1 if it isn't able to
int EntityDrawable::init(std::map<std::string, Asset> assets, EventListeners* l) {
  
  listeners = l;

  if (assets.find(path) == assets.end()) {
    std::cout << "error! asset " << path << "could not be initialized properly!\n";
    return 1;
  }

  texture = assets[path].getTexture();

  box.setTexture(texture, true);

  listeners->subscribe("draw", [this](sf::RenderWindow* w) { draw(w); }, this);

  return 0;
}

// For now it just moves the image
void EntityDrawable::update(float time) {


}

// No need to comment
void EntityDrawable::draw(sf::RenderWindow* window) {

  box.setPosition(entity->getPosition());
  
  box.setTextureRect(getTexturePosition());
  window->draw(box);
  
}


// returns a list containing only the texture
std::set<const char*> EntityDrawable::getAssetPathList() const {
  std::set<const char*> list;
  list.insert(path);
  return list;
}

const sf::IntRect EntityDrawable::getTexturePosition() const {
  
return (entity->isFacingRight()) ?  
  
  sf::IntRect{
    sf::Vector2i{
      static_cast<int>(texture->getSize().x) * entity->getTexturePosition().x / (frames.x), 
      static_cast<int>(texture->getSize().y) * entity->getTexturePosition().y / (frames.y)
    },
   sf::Vector2i{static_cast<int>(texture->getSize().x) / frames.x, static_cast<int>(texture->getSize().y) / frames.y}} :
  
  sf::IntRect{
    sf::Vector2i{
      static_cast<int>(texture->getSize().x) * (entity->getTexturePosition().x + 1) / (frames.x), 
      static_cast<int>(texture->getSize().y) * entity->getTexturePosition().y / (frames.y)
    },
   sf::Vector2i{- static_cast<int>(texture->getSize().x) / frames.x, static_cast<int>(texture->getSize().y) / frames.y}};
 /* 
  return sf::IntRect{
    sf::Vector2i{
      static_cast<int>(texture->getSize().x) * (entity->getTexturePosition().x + (entity->isFacingRight()) ? 0 : 1) / (frames.x), 
      static_cast<int>(texture->getSize().y) * entity->getTexturePosition().y / (frames.y)
    },
    sf::Vector2i{( (entity->isFacingRight()) ? (1) : (-1)) *static_cast<int>(texture->getSize().x) / frames.x, static_cast<int>(texture->getSize().y) / frames.y}
  };
     */ 

}

} // namespace HE