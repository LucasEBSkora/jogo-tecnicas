#include "Drawable.h"

FISW::Drawable::Drawable(const char* Path, float X, float Y) : path(Path), x(X), y(Y) {

}

FISW::Drawable::~Drawable() {

}


std::list<const char*> FISW::Drawable::getAssetPathList() {
  std::list<const char*> list;
  list.push_back(path);
  return list;
}

int FISW::Drawable::init(std::map<const char*, sf::Texture*> *assets) {

  if (assets->find(path) == assets->end) return 1;

  texture = (*assets)[path];

  return 0;
}

void FISW::Drawable::update() {

}

void FISW::Drawable::draw(sf::RenderWindow *window) {
  sf::RectangleShape box;
  box.setPosition(sf::Vector2f(100.0f,100.0f));
  box.setTexture(texture);

  window->draw(box);

}
