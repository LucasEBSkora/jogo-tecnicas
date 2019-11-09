#include "StaticDrawable.hpp"

#include <functional>
#include <iostream>

namespace HE {

StaticDrawable::StaticDrawable(const char* Path, float X, float Y, float Length, float Height)
  : path { Path }
  , x { X }
  , y { Y }
  , length { Length }
  , height { Height }
  , texture { nullptr }
  , box { sf::Vector2f(Length, Height) } {

  box.setPosition(X, Y);
}

StaticDrawable::~StaticDrawable() {
}

// returns a list containing only the texture
std::set<const char*> StaticDrawable::getAssetPathList() const {
  std::set<const char*> list;
  list.insert(path);
  return list;
}

// this class depends on update and draw events
// EventListeners StaticDrawable::getSettings() {
//   // it can be done either way:
//   // with lambdas
//   auto update_fun = [this](float time) { update(time); };
//   // std::function<void(float)> update = std::bind(static_cast<void(StaticDrawable::*)(float)>(&StaticDrawable::update), this,
//   // std::placeholders::_1);

//   // with std::bind
//   auto draw_fun = std::bind(&StaticDrawable::draw, this, std::placeholders::_1);

//   EventListeners settings;
//   settings.addUpdate(update_fun);
//   settings.addDraw(draw_fun);
//   settings.addTimer(sf::seconds(1), [this]() {update(-1);});
//   return settings;
// }

// Finds the asset in the map using the path as a key, returns 1 if it isn't able to
int StaticDrawable::init(std::map<std::string, Asset> assets, EventListeners* l) {
  
  listeners = l; // se ele é const como a gente vai mudar?


  if (assets.find(path) == assets.end()) {
    std::cout << "error! asset " << path << "could not be initialized properly!\n";
    return 1;
  }

  texture = assets[path].getTexture();

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
void StaticDrawable::update(float time) {
  box.move(sf::Vector2f(time * 40.0f, time * 20.0f));
}

// No need to comment
void StaticDrawable::draw(sf::RenderWindow* window) {
  window->draw(box);
}

} // namespace HE