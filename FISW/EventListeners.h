#ifndef EVENTHANDLERLISTENERS_H
#define EVENTHANDLERLISTENERS_H

#include <functional>
#include <vector>

#include <SFML/Graphics.hpp>

#include "constants.h"

namespace FISW {

// needs to be redone in a more event oriented way
// being redone
// enum EventTypes {
//     UpdateEvent,
//     DrawEvent,
//     KeyboardEvent,
//     MouseEvent,
// };


class EventListeners {

private:
  std::vector<std::function<void(float)>> updates;
  std::vector<std::function<void(sf::RenderWindow*)>> draws;
  std::vector<std::function<void(sf::Event*)>> keyboards;
  std::vector<std::function<void(sf::Event*)>> mouses;
  std::vector<std::function<void(sf::Event*)>> systemEvents;
  std::multimap<sf::Time, std::function<void()>> timers;

public:
  EventListeners();

  ~EventListeners();

  // joins the sets that compose the settings
  void join(const EventListeners& settings);

  // adds functions to the vectors
  void addUpdate(std::function<void(float)> f);
  void addDraw(std::function<void(sf::RenderWindow*)> f);
  void addKeyboard(std::function<void(sf::Event*)> f);
  void addMouse(std::function<void(sf::Event*)> f);
  void addTimer(sf::Time, std::function<void()> f);
  void addSystem(std::function<void(sf::Event*)> f);

  friend class EventHandler;
};

} // namespace FISW

#endif