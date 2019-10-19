#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "EventListeners.h"
#include <SFML/Graphics.hpp>

namespace FISW {

// needs to be redone in a more event oriented way

class EventHandler {

private:
  EventListeners settings;
  sf::Clock clock;

  //inverse of framerate, basically
  static const sf::Time timePerFrame;

  //time since last processEvents() call
  sf::Time timeSinceLastUpdate;

  //Vector of time values used to keep track of timers with different periods
  std::vector<sf::Time> timers;

public:
  EventHandler(EventListeners Settings = EventListeners());
  ~EventHandler();

  
  void updateSettings(EventListeners Settings);

  //returns true if there was an error during event processing
  bool processEvents(sf::RenderWindow* window);
    
  void resetTime();
};

} // namespace FISW

#endif

//Thiago vou comentar o que entendi que são as coisas se estiver errado avisa