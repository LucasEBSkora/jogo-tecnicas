#include "Asset.hpp"

#include <iostream>
namespace FISW {
  
  Asset::Asset() : texture{nullptr} {

  }

  Asset::~Asset() {}

  sf::Texture* Asset::getTexture() const {
    return texture;
  }

  bool Asset::load(const char* path) {

    if (std::string{path}.find(".png") != std::string::npos) {
      
      texture = new sf::Texture();
      bool success = texture->loadFromFile(path);
      return success;


    } else return false;
    
  }

  void Asset::destroy() {
    if (texture) delete texture;
  }

}