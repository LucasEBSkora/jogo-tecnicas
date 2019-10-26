#include "Animatable.hpp"

#include <iostream>

namespace FISW {

Animatable::Animatable(const char* Path, sf::Vector2f initialPosition, sf::IntRect initialTexturePosition, sf::Vector2f Size)
  : path { Path }
  , position{initialPosition}
  , size {Size}
  , texturePosition{initialTexturePosition}
  , texture {nullptr }
  , box {Size} {

  box.setPosition(initialPosition);
}

Animatable::~Animatable() {
}

// returns a list containing only the texture
std::list<const char*> Animatable::getAssetPathList() const {
  std::list<const char*> list;
  list.push_back(path);
  return list;
}

// Finds the asset in the map using the path as a key, returns 1 if it isn't able to
int Animatable::init(std::map<std::string, sf::Texture*> assets, EventListeners* l) {
  
  listeners = l;

  if (assets.find(path) == assets.end()) {
    std::cout << "error! asset " << path << "could not be initialized properly!\n";
    return 1;
  }

  texture = assets[path];

  box.setTexture(texture, true);

  listeners->subscribe("update", [this](float time) { update(time); }, this);
  listeners->subscribe("draw", [this](sf::RenderWindow* w) { draw(w); }, this);
  listeners->subscribe("timer_300", [this](){
    texturePosition.left += texture->getSize().x/9;
    if (texturePosition.left >= texture->getSize().x)  texturePosition.left = 0;
  
  }, this);
  

  return 0;
}

// For now it just moves the image
void Animatable::update(float time) {
  box.setTextureRect(texturePosition);
  box.move(sf::Vector2f(time * 40.0f, time * 20.0f));
}

// No need to comment
void Animatable::draw(sf::RenderWindow* window) {
  window->draw(box);
}

} // namespace FISW