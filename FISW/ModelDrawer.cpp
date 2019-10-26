#include "ModelDrawer.hpp"
#include "Model.hpp"

#include <iostream>

namespace FISW {

ModelDrawer::ModelDrawer(const char* Path, sf::Vector2f Size, const Model* Model, sf::Vector2i numberFrames) :
  path{Path},
  size{Size},
  frames{numberFrames},
  model{Model},
  box{Size} {

  box.setPosition(model->getPosition());
}

ModelDrawer::~ModelDrawer() {
}

// returns a list containing only the texture
std::list<const char*> ModelDrawer::getAssetPathList() const {
  std::list<const char*> list;
  list.push_back(path);
  return list;
}

// Finds the asset in the map using the path as a key, returns 1 if it isn't able to
int ModelDrawer::init(std::map<std::string, sf::Texture*> assets, EventListeners* l) {
  
  listeners = l;

  if (assets.find(path) == assets.end()) {
    std::cout << "error! asset " << path << "could not be initialized properly!\n";
    return 1;
  }

  texture = assets[path];

  box.setTexture(texture, true);

  listeners->subscribe("draw", [this](sf::RenderWindow* w) { draw(w); }, this);

  return 0;
}

// For now it just moves the image
void ModelDrawer::update(float time) {


}

// No need to comment
void ModelDrawer::draw(sf::RenderWindow* window) {

  box.setPosition(model->getPosition());
  
  box.setTextureRect(getTexturePosition());
  window->draw(box);
  
}

const sf::IntRect ModelDrawer::getTexturePosition() const {
  
  return (model->isFacingRight()) ?  
  
  sf::IntRect{
    sf::Vector2i{
      static_cast<int>(texture->getSize().x) * model->getTexturePosition().x / (frames.x), 
      static_cast<int>(texture->getSize().y) * model->getTexturePosition().y / (frames.y)
    },
   sf::Vector2i{static_cast<int>(texture->getSize().x) / frames.x, static_cast<int>(texture->getSize().y) / frames.y}} :
  
  sf::IntRect{
    sf::Vector2i{
      static_cast<int>(texture->getSize().x) * (model->getTexturePosition().x + 1) / (frames.x), 
      static_cast<int>(texture->getSize().y) * model->getTexturePosition().y / (frames.y)
    },
   sf::Vector2i{- static_cast<int>(texture->getSize().x) / frames.x, static_cast<int>(texture->getSize().y) / frames.y}};
   
}

} // namespace FISW