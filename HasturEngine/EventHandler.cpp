#include "EventHandler.hpp"

#include <iostream>
#include <string>

namespace HE {
const sf::Time EventHandler::timePerFrame{sf::seconds(1.0f / 60.0f)};

EventHandler::EventHandler(EventListeners Listeners)
  : listeners { Listeners }
  , timeSinceLastUpdate { sf::Time::Zero } {
}

EventHandler::~EventHandler() {
}

bool EventHandler::processEvents(sf::RenderWindow* window) {

  sf::Time elapsedTime = clock.restart();
  timeSinceLastUpdate += elapsedTime;

  for (auto& t : listeners.timers) {
    std::get<0>(t.second) += elapsedTime;
  }

  // for (auto& t : listeners.timers) {
  //   std::cout << std::get<0>(t.second).asMilliseconds() << std::endl;
  // }

  // std::size_t i = 0;
  // for (auto it = listeners.timers.begin(); it != listeners.timers.end(); ) {
  //   auto key = it->first;
  //   if (timers[i] >= key) {
  //     auto range = listeners.timers.equal_range(key);
  //     for (auto pair = range.first; pair != range.second; ++pair) {
  //       pair->second();
  //     }
  //     timers[i] -= key;
  //   }
  //   do {
  //     ++it;
  //   } while (it != listeners.timers.end() && key == it->first);
  //   ++i;
  // }
  for (auto& t : listeners.timers) {

    if (std::get<0>(t.second) >= std::get<1>(t.second)) {
      std::get<0>(t.second) -= std::get<1>(t.second);
      std::get<2>(t.second)();
    }
  }

  while (timeSinceLastUpdate > timePerFrame) {

    timeSinceLastUpdate -= timePerFrame;
    sf::Event evnt;

    while (window->pollEvent(evnt)) {

      if (evnt.type == sf::Event::TextEntered) {
        if (evnt.text.unicode < 128)
          std::cout << static_cast<char>(evnt.text.unicode) << std::flush;

      } else if (evnt.type == sf::Event::KeyPressed || evnt.type == sf::Event::KeyReleased) {
        for (auto& f : listeners.keyboards) {
          f.second(&evnt);
        }
      } 
       else if (evnt.type == sf::Event::MouseMoved) {
        for (auto& f : listeners.mouses) {
          f.second(&evnt);
        }
      } else { 
        for (auto& f : listeners.systemEvents) {
          f.second(&evnt);
        }
      }
    }
    // update things
    for (auto& f : listeners.updates) {
      f.second(timePerFrame.asSeconds());
    }
  }
  // draw things
  window->clear();
  for (auto& f : listeners.draws) {
    f.second(window);
  }
  window->display();
  return true;
}

void EventHandler::resetTime() {
  timeSinceLastUpdate = sf::Time::Zero;
}

const EventListeners* EventHandler::getListener() const {
  return &(listeners);
}

EventListeners* EventHandler::getListener() {
  return &(listeners);
}

} // namespace HE