#include "EventHandler.h"

#include <iostream>
#include <string>

namespace FISW {
const sf::Time EventHandler::timePerFrame{sf::seconds(1.0f / 60.0f)};

EventHandler::EventHandler(EventListeners Settings)
  : settings { Settings }
  , timeSinceLastUpdate { sf::Time::Zero } {
}

EventHandler::~EventHandler() {
}

void EventHandler::updateSettings(EventListeners Settings) {
  settings = Settings;
  timers.clear();

  for (auto it = settings.timers.begin(); it != settings.timers.end(); ) {
    auto key = it->first;
    timers.push_back(sf::Time::Zero);
    do {
      ++it;
    } while (it != settings.timers.end() && key == it->first);
  }
}

//Se a gente fizer um evento de "botão de fechar apertado" essa função retornaria apenas se aconteceu algum erro

bool EventHandler::processEvents(sf::RenderWindow* window) {

  sf::Time elapsedTime = clock.restart();
  timeSinceLastUpdate += elapsedTime;

  for (auto& t : timers) {
    t += elapsedTime;
  }

  std::size_t i = 0;
  for (auto it = settings.timers.begin(); it != settings.timers.end(); ) {
    auto key = it->first;
    if (timers[i] >= key) {
      auto range = settings.timers.equal_range(key);
      for (auto pair = range.first; pair != range.second; ++pair) {
        pair->second();
      }
      timers[i] -= key;
    }
    do {
      ++it;
    } while (it != settings.timers.end() && key == it->first);
    ++i;
  }

  while (timeSinceLastUpdate > timePerFrame) {

    timeSinceLastUpdate -= timePerFrame;
    sf::Event evnt;

    while (window->pollEvent(evnt)) {

      if (evnt.type == sf::Event::TextEntered) {
        if (evnt.text.unicode < 128)
          std::cout << static_cast<char>(evnt.text.unicode) << std::flush;

      } else if (evnt.type == sf::Event::KeyPressed) {
        for (auto f : settings.keyboards) {
          f(&evnt);
        }
      } 
       else if (evnt.type == sf::Event::MouseMoved) {
        for (auto f : settings.mouses) {
          f(&evnt);
        }
      } else { 
        for (auto f : settings.systemEvents) {
          f(&evnt);
        }
      }
    }
    // update things
    for (auto f : settings.updates) {
      f(timePerFrame.asSeconds());
    }
  }
  // draw things
  window->clear();
  for (auto f : settings.draws) {
    f(window);
  }
  window->display();
  return true;
}

void EventHandler::resetTime() {
  timeSinceLastUpdate = sf::Time::Zero;
}

} // namespace FISW