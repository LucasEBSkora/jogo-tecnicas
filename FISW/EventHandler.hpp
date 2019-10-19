#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "EventListeners.hpp"
#include <SFML/Graphics.hpp>

namespace FISW {

class EventHandler {

private:
  EventListeners listeners;
  sf::Clock clock;

  //inverse of framerate, basically
  static const sf::Time timePerFrame;

  //time since last processEvents() call
  sf::Time timeSinceLastUpdate;

  //Vector of time values used to keep track of timers with different periods
  std::vector<sf::Time> timers;

public:
  EventHandler(EventListeners Listeners = EventListeners());
  ~EventHandler();

  
  //returns true if there was an error during event processing
  bool processEvents(sf::RenderWindow* window);

  const EventListeners* getListener() const; 
  EventListeners* getListener();

  void resetTime();
};

} // namespace FISW

#endif
