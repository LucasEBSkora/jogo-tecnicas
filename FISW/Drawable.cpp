#include "Drawable.h"
#include <iostream>

FISW::Drawable::Drawable(const char* Path, float X, float Y) : path{Path}, x{X}, y{Y}, texture{NULL} {
  std::cout << "mano";

}

FISW::Drawable::~Drawable() {

}


std::list<const char*> FISW::Drawable::getAssetPathList() {
  std::list<const char*> list;
  list.push_back(path);
  return list;
}

int FISW::Drawable::init(std::map<std::string, sf::Texture*> assets) {

  if (assets.find(path) == assets.end())  {
    std::cout << "error! asset " << path << "could not be initialized properly!\n";
    return 1;
  }

  texture = assets[path];


  return 0;
}

void FISW::Drawable::update() {

}

void FISW::Drawable::draw(sf::RenderWindow *window) {
  
  sf::RectangleShape box(sf::Vector2f(100.0f, 100.0f));
  box.setPosition(sf::Vector2f(100.0f,100.0f));
  box.setTexture(texture, true);
  
  window->draw(box);

}
