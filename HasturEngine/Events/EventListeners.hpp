#ifndef EVENTHANDLERLISTENERS_H
#define EVENTHANDLERLISTENERS_H

#include <functional>
#include <vector>
#include <iostream>
#include <sstream>
#include <type_traits>

#include <SFML/Graphics.hpp>

#include "../constants.hpp"

namespace HE {



class EventListeners {

private:
  std::map<std::string, std::function<void(float)>> updates;
  std::map<std::string, std::function<void(sf::RenderWindow*)>> draws;
  std::map<std::string, std::function<void(sf::Event*)>> keyboards;
  std::map<std::string, std::function<void(sf::Event*)>> mouses;
  std::map<std::string, std::function<void(sf::Event*)>> systemEvents;
  std::map<std::string, std::tuple<sf::Time, sf::Time, std::function<void()>>> timers;
  // std::multimap<sf::Time, std::function<void()>> timers;

public:
  EventListeners();

  ~EventListeners();

  template <typename T>
  void subscribe(const std::string& eventName, T callback, void* subscriber=nullptr);
  void unsubscribe(const std::string& eventName, void* subscriber);
  void pushEvent(const std::string& eventName);


  friend class EventHandler;
};

template <typename T>
void EventListeners::subscribe(const std::string& eventName, T callback, void* subscriber) {
  std::stringstream s(eventName);
  s << subscriber;
  std::string key = s.str();
  if (eventName == "update") {
    if constexpr (std::is_convertible<T, std::function<void(float)>>::value) {
      updates.insert({key, static_cast<std::function<void(float)>>(callback)});
    }
  } else if (eventName == "draw") {
    if constexpr (std::is_convertible<T, std::function<void(sf::RenderWindow*)>>::value) {
      draws.insert({key, static_cast<std::function<void(sf::RenderWindow*)>>(callback)});
    }
  } else if (eventName == "keyboard") {
    if constexpr (std::is_convertible<T, std::function<void(sf::Event*)>>::value) {
      keyboards.insert({key, static_cast<std::function<void(sf::Event*)>>(callback)});
    }
  } else if (eventName == "mouse") {
    if constexpr (std::is_convertible<T, std::function<void(sf::Event*)>>::value) {
      mouses.insert({key, static_cast<std::function<void(sf::Event*)>>(callback)});
    }
  } else if (eventName == "system") {
    if constexpr (std::is_convertible<T, std::function<void(sf::Event*)>>::value) {
      systemEvents.insert({key, static_cast<std::function<void(sf::Event*)>>(callback)});
    }
  } else if (eventName.find("timer_") != std::string::npos) {
    std::stringstream ss;
    ss << eventName.substr(6);
    // std::cout << eventName.substr(6) << ' ' << ss.str() << std::endl;
    int milliseconds = 0;
    ss >> milliseconds;
    if (milliseconds > 0) {
    
      if constexpr (std::is_convertible<T, std::function<void()>>::value) {
        std::cout << "subscribing to a timer!!!" << std::endl; 

        timers.insert({key, std::make_tuple(sf::Time::Zero, sf::milliseconds(milliseconds), static_cast<std::function<void()>>(callback))});
      }
    }
  } else {

  }
  // } else if (eventName.find("timer") != std::string::npos)) {
  //   timers;
  // }
}

} // namespace HE

#endif