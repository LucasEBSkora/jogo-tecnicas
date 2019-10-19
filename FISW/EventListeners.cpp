#include "EventListeners.h"

namespace FISW {

EventListeners::EventListeners() {
}

EventListeners::~EventListeners() {
}

void EventListeners::join(const EventListeners& settings) {

  // joins the sets
  updates.insert(updates.end(), settings.updates.begin(), settings.updates.end());
  draws.insert(draws.end(), settings.draws.begin(), settings.draws.end());
  keyboards.insert(keyboards.end(), settings.keyboards.begin(), settings.keyboards.end());
  mouses.insert(mouses.end(), settings.mouses.begin(), settings.mouses.end());
  timers.insert(settings.timers.begin(), settings.timers.end());
  systemEvents.insert(systemEvents.end(), settings.systemEvents.begin(), settings.systemEvents.end());
}

void EventListeners::addUpdate(std::function<void(float)> f) {
  updates.push_back(f);
}

void EventListeners::addDraw(std::function<void(sf::RenderWindow*)> f) {
  draws.push_back(f);
}

void EventListeners::addKeyboard(std::function<void(sf::Event*)> f) {
  keyboards.push_back(f);
}

void EventListeners::addMouse(std::function<void(sf::Event*)> f) {
  mouses.push_back(f);

}

void EventListeners::addTimer(sf::Time t, std::function<void()> f) {
  timers.insert({t, f});
}

void EventListeners::addSystem(std::function<void(sf::Event*)> f) {
  systemEvents.push_back(f);

}



} // namespace FISW
