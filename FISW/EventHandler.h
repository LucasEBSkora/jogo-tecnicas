#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "EventHandlerSettings.h"
#include "EventReport.h"
#include <SFML/Graphics.hpp>

namespace FISW {

// needs to be redone in a more event oriented way

class EventHandler {

private:
  EventHandlerSettings settings;
  EventReport report;
  sf::Clock clock;
  static const sf::Time timePerFrame;
  sf::Time timeSinceLastUpdate;

public:
  EventHandler(EventHandlerSettings Settings = EventHandlerSettings());
  ~EventHandler();

  void updateSettings(EventHandlerSettings Settings);
  const EventReport& processEvents(sf::RenderWindow* window);
  void resetTime();
};

} // namespace FISW

#endif