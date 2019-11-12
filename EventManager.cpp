#include "EventManager.hpp"

#include <iostream>
#include <string>

namespace DIM {
  
  int EventManager::next_uid = 0;

  EventManager::EventManager() : graphics_manager(nullptr),
    timeSinceLastUpdate(sf::Time::Zero) {

  }

  EventManager::~EventManager() {

  }

  void EventManager::setGraphicsManager(GraphicsManager* manager) {
    graphics_manager = manager;
  }

  GraphicsManager* EventManager::getGraphicsManager() const {
    return graphics_manager;
  }

  int EventManager::addTimer(float seconds, std::function<void()> callback) {
    timers_callbacks[next_uid] = std::make_tuple(sf::seconds(seconds), sf::Time::Zero, callback);
    return next_uid++;
  }

  void EventManager::removeTimer(int id) {
    timers_callbacks.erase(id);
  }

  int EventManager::addKeyboardListener(std::function<void(Key, EventType)> callback) {
    keyboard_callbacks[next_uid] = callback;
    return next_uid++;
  }

  void EventManager::removeKeyboardListener(int id) {
    keyboard_callbacks.erase(id);
  }

  int EventManager::addMouseListener(std::function<void(Button, EventType)> callback) {
    mouse_callbacks[next_uid] = callback;
    return next_uid++;
  }

  void EventManager::removeMouseListener(int id) {
    mouse_callbacks.erase(id);
  }

  void EventManager::processEvents() {

    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    for (auto& t : timers_callbacks) {
      std::get<1>(t.second) += elapsedTime;
    }

    // for (auto& t : listeners.timers) {
    //   std::cout << std::get<0>(t.second).asMilliseconds() << std::endl;
    // }

    for (auto& t : timers_callbacks) {

      if (std::get<1>(t.second) >= std::get<0>(t.second)) {
        std::get<1>(t.second) -= std::get<0>(t.second);
        std::get<2>(t.second)();
      }
    }

    sf::Event event;

    while (graphics_manager->getWindow()->pollEvent(event)) {

      if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128)
          std::cout << static_cast<char>(event.text.unicode) << std::flush;

      } else if (event.type == sf::Event::KeyPressed) { // fazer de um jeito melhor (mas não é urgente)
        if (event.key.code == sf::Keyboard::Escape) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::Esc, EventType::Pressed);
          }
        }
      } else if (event.type == sf::Event::MouseButtonPressed) {
        for (auto& f : mouse_callbacks) {
          f.second(Button::Left, EventType::Clicked);
        }
      }
    }
  }

  float EventManager::getLastElapsedTime() const {
    return timeSinceLastUpdate.asSeconds();
  }

  void EventManager::resetTime() {
    clock.restart();
    timeSinceLastUpdate = sf::Time::Zero;
  }

}