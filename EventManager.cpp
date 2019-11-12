#include "EventManager.hpp"

#include <iostream>
#include <string>

namespace DIM {
  
  int EventManager::next_uid = 0;

  EventManager::EventManager() : graphics_manager(nullptr),
    lastElapsedTime(sf::Time::Zero) {

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

    lastElapsedTime = clock.restart();
    // timeSinceLastUpdate += elapsedTime;

    for (auto& t : timers_callbacks) {
      std::get<1>(t.second) += lastElapsedTime;
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
        } else if (event.key.code == sf::Keyboard::W) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::W, EventType::Pressed);
          }
        } else if (event.key.code == sf::Keyboard::A) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::A, EventType::Pressed);
          }
        } else if (event.key.code == sf::Keyboard::S) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::S, EventType::Pressed);
          }
        } else if (event.key.code == sf::Keyboard::D) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::D, EventType::Pressed);
          }
        }
      } else if (event.type == sf::Event::KeyReleased) { // fazer de um jeito melhor (mas não é urgente)
        if (event.key.code == sf::Keyboard::Escape) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::Esc, EventType::Released);
          }
        } else if (event.key.code == sf::Keyboard::W) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::W, EventType::Released);
          }
        } else if (event.key.code == sf::Keyboard::A) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::A, EventType::Released);
          }
        } else if (event.key.code == sf::Keyboard::S) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::S, EventType::Released);
          }
        } else if (event.key.code == sf::Keyboard::D) {
          for (auto& f : keyboard_callbacks) {
            f.second(Key::D, EventType::Released);
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
    return lastElapsedTime.asSeconds();
  }

  void EventManager::resetTime() {
    clock.restart();
    lastElapsedTime = sf::Time::Zero;
  }

}