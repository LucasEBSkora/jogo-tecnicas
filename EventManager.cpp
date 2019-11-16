#include "EventManager.hpp"

#include <iostream>
#include <string>

namespace DIM {
  
  int EventManager::next_uid = 0;

  EventManager::Event::Event() {
    
  }

  EventManager::Event::Event(sf::Event& ev) : event(ev) {
    
  }

  EventManager::Event::~Event() {

  }

  void EventManager::Event::setEvent(sf::Event ev) {
    event = ev;
  }

  EventManager::EventType EventManager::Event::getType() const {
    switch (event.type) {
      case sf::Event::EventType::KeyPressed:
        return EventType::KeyPressed;
      case sf::Event::EventType::KeyReleased:
        return EventType::KeyReleased;
      case sf::Event::EventType::MouseWheelScrolled:
       
        if (event.mouseWheelScroll.delta > 0) return EventType::MouseWheelScrolledUp;
        else return EventType::MouseWheelScrolledDown;
        
      case sf::Event::EventType::MouseButtonPressed:
        return EventType::MouseButtonPressed;
      case sf::Event::EventType::MouseButtonReleased:
        return EventType::MouseButtonReleased;
      default:
        return EventType::Other;
    }
  }

  EventManager::MouseButton EventManager::Event::getMouseButton() const {
    return static_cast<EventManager::MouseButton>(event.mouseButton.button);
  }

  EventManager::Key EventManager::Event::getKey() const {
    return static_cast<EventManager::Key>(event.key.code);
  }

  EventManager::EventManager() : graphics_manager(nullptr),
    lastElapsedTime(sf::Time::Zero) {

  }

  EventManager::~EventManager() {

  }

  void EventManager::setGraphicsManager(GraphicsManager& manager) {
    graphics_manager = &manager;
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

  int EventManager::addKeyboardListener(std::function<void(Event)> callback) {
    keyboard_callbacks[next_uid] = callback;
    return next_uid++;
  }

  void EventManager::removeKeyboardListener(int id) {
    keyboard_callbacks.erase(id);
  }

  int EventManager::addMouseListener(std::function<void(Event)> callback) {
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


      Event event_obj = Event(event);
      
      if (event_obj.getType() == EventType::KeyPressed ||
          event_obj.getType() == EventType::KeyReleased) {
        for (auto& f : keyboard_callbacks) {
          f.second(event_obj);
        }
      } else if (event_obj.getType() != EventType::Other) {
        for (auto& f : mouse_callbacks) {
          f.second(event_obj);
        }
      }
      // if (event.type == sf::Event::TextEntered) {
      //   if (event.text.unicode < 128)
      //     std::cout << static_cast<char>(event.text.unicode) << std::flush;

      // } else if (event_obj.getType() == EventType::KeyPressed ||
      //            event_obj.getType() == EventType::KeyReleased) { 
      //   for (auto& f : keyboard_callbacks) {
      //     f.second(event_obj);
      //   }
        
      // } else if (event_obj.getType() == EventType::MouseButtonPressed ||
      //            event_obj.getType() == EventType::MouseButtonReleased ||
      //            event_obj.getType() == EventType::MouseWheelScrolled) {
      //   for (auto& f : mouse_callbacks) {
      //     f.second(event_obj);
      //   }
      // }
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