#include "Drawable.hpp"

#include <functional>
#include <iostream>

namespace FISW {

Drawable::Drawable(const char* Path, float X, float Y, float Length, float Height)
  : path { Path }
  , x { X }
  , y { Y }
  , length { Length }
  , height { Height }
  , texture { nullptr }
  , box { sf::Vector2f(Length, Height) } {

  box.setPosition(X, Y);
}

Drawable::~Drawable() {
}

// returns a list containing only the texture
std::list<const char*> Drawable::getAssetPathList() const {
  std::list<const char*> list;
  list.push_back(path);
  return list;
}

// this class depends on update and draw events
// EventListeners Drawable::getSettings() {
//   // it can be done either way:
//   // with lambdas
//   auto update_fun = [this](float time) { update(time); };
//   // std::function<void(float)> update = std::bind(static_cast<void(Drawable::*)(float)>(&Drawable::update), this,
//   // std::placeholders::_1);

//   // with std::bind
//   auto draw_fun = std::bind(&Drawable::draw, this, std::placeholders::_1);

//   EventListeners settings;
//   settings.addUpdate(update_fun);
//   settings.addDraw(draw_fun);
//   settings.addTimer(sf::seconds(1), [this]() {update(-1);});
//   return settings;
// }

// Finds the asset in the map using the path as a key, returns 1 if it isn't able to
int Drawable::init(std::map<std::string, sf::Texture*> assets, EventListeners* l) {
  
  listeners = l; // se ele é const como a gente vai mudar?


  if (assets.find(path) == assets.end()) {
    std::cout << "error! asset " << path << "could not be initialized properly!\n";
    return 1;
  }

  texture = assets[path];

  box.setTexture(texture, true);

  listeners->subscribe("update", [this](float time) { update(time); }, this);
  listeners->subscribe("draw", [this](sf::RenderWindow* w) { draw(w); }, this);

  listeners->unsubscribe("update", this);
  listeners->subscribe("update", [this](float time) { update(time); }, this);

  listeners->subscribe("timer_1000", [this]() { update(-1); }, this);
  listeners->subscribe("timer_7000", [this]() { listeners->unsubscribe("timer_1000", this); });
  listeners->pushEvent("drawable_init");

  return 0;
}

// For now it just moves the image
void Drawable::update(float time) {
  box.move(sf::Vector2f(time * 40.0f, time * 20.0f));
}

// No need to comment
void Drawable::draw(sf::RenderWindow* window) {
  window->draw(box);
}

} // namespace FISW