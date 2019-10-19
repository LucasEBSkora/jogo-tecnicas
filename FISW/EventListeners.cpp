#include "EventListeners.hpp"

namespace FISW {

EventListeners::EventListeners() {
}

EventListeners::~EventListeners() {

}

void EventListeners::unsubscribe(const std::string& eventName, void* subscriber) {
  std::stringstream s(eventName);
  s << subscriber;
  std::string key = s.str();
  if (eventName == "update") {
    updates.erase(key);
  } else if (eventName == "draw") {
    draws.erase(key);
  } else if (eventName == "keyboard") {
    keyboards.erase(key);
  } else if (eventName == "mouse") {
    mouses.erase(key);
  } else if (eventName == "system") {
    systemEvents.erase(key);
  } else if (eventName.find("timer_") != std::string::npos) {
    timers.erase(key);
  } else {

  }
}

void EventListeners::pushEvent(const std::string& eventName) {
  
}

} // namespace FISW
