#include "Animatable.hpp"

#include <iostream>

namespace FISW {

Animatable::Animatable(const char* Path, sf::Vector2f pos, sf::Vector2f Size, std::map<std::string, AnyCallable<void>> events)
  : path { Path }
  , position{pos}
  , size {Size}
  , lambdas{events} 
  , texture {nullptr }
  , box {Size} {

  box.setPosition(pos);
}

Animatable::~Animatable() {
}

// returns a list containing only the texture
std::list<const char*> Animatable::getAssetPathList() const {
  std::list<const char*> list;
  list.push_back(path);
  return list;
}

// this class depends on update and draw events
// EventListeners Animatable::getSettings() {
//   // it can be done either way:
//   // with lambdas
//   auto update_fun = [this](float time) { update(time); };
//   // std::function<void(float)> update = std::bind(static_cast<void(Animatable::*)(float)>(&Animatable::update), this,
//   // std::placeholders::_1);

//   // with std::bind
//   auto draw_fun = std::bind(&Animatable::draw, this, std::placeholders::_1);

//   EventListeners settings;
//   settings.addUpdate(update_fun);
//   settings.addDraw(draw_fun);
//   settings.addTimer(sf::seconds(1), [this]() {update(-1);});
//   return settings;
// }

// Finds the asset in the map using the path as a key, returns 1 if it isn't able to
int Animatable::init(std::map<std::string, sf::Texture*> assets, EventListeners* l) {
  
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
void Animatable::update(float time) {
  box.move(sf::Vector2f(time * 40.0f, time * 20.0f));
}

// No need to comment
void Animatable::draw(sf::RenderWindow* window) {
  window->draw(box);
}

} // namespace FISW