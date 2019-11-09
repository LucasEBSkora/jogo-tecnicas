#include "DynamicDrawable.hpp"

#include <iostream>

namespace HE {

DynamicDrawable::DynamicDrawable(const char* Path, sf::Vector2f initialPosition, sf::IntRect initialTexturePosition, sf::Vector2f Size)
  : path { Path }
  , position{initialPosition}
  , size {Size}
  , texturePosition{initialTexturePosition}
  , texture {nullptr }
  , box {Size} {

  box.setPosition(initialPosition);
}

DynamicDrawable::~DynamicDrawable() {
}

// returns a list containing only the texture
std::set<const char*> DynamicDrawable::getAssetPathList() const {
  std::set<const char*> list;
  list.insert(path);
  return list;
}

// Finds the asset in the map using the path as a key, returns 1 if it isn't able to
int DynamicDrawable::init(std::map<std::string, Asset> assets, EventListeners* l) {
  
  listeners = l;

  if (assets.find(path) == assets.end()) {
    std::cout << "error! asset " << path << "could not be initialized properly!\n";
    return 1;
  }

  texture = assets[path].getTexture();

  box.setTexture(texture, true);

  listeners->subscribe("update", [this](float time) { update(time); }, this);
  listeners->subscribe("draw", [this](sf::RenderWindow* w) { draw(w); }, this);
  
  listeners->subscribe("timer_300", [this](){
    texturePosition.left += static_cast<int> (texture->getSize().x/9);
    if (static_cast<unsigned int> (texturePosition.left) >= texture->getSize().x)  texturePosition.left = 0;
  
  }, this);
  

  return 0;
}

// For now it just moves the image
void DynamicDrawable::update(float time) {
  box.setTextureRect(texturePosition);
  box.move(sf::Vector2f(time * 40.0f, time * 20.0f));
}

// No need to comment
void DynamicDrawable::draw(sf::RenderWindow* window) {
  window->draw(box);
}

} // namespace HE