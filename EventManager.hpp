#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <functional>
#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"

namespace DIM {

  class EventManager {
  private:
    GraphicsManager* graphics_manager;
    // sf::Clock clock;

    //inverse of framerate, basically
    // static const sf::Time timePerFrame;

    //time since last processEvents() call
    // sf::Time timeSinceLastUpdate;

    //Vector of time values used to keep track of timers with different periods
    // std::vector<sf::Time> timers;

  public:
    enum class Key {
      W,
      A,
      S,
      D,
      Esc,
    };

    enum class Button {
      Left,
      Middle,
      Right,
    };

    enum class EventType {
      Pressed,
      Released,
      Clicked,
      WheelUp,
      WheelDown,
    };
    // tá quase virando um sf::Event

    EventManager();
    ~EventManager();

    void setGraphicsManager(GraphicsManager* manager);
    GraphicsManager* getGraphicsManager() const;
    
    int addTimer(float seconds, std::function<void()> callback);
    void removeTimer(int id);

    int addKeyboardListener(std::function<void(Key, EventType)> callback);
    void removeKeyboardListener(int id);

    int addMouseListener(std::function<void(Button, EventType)> callback);
    void removeMouseListener(int id);

    //returns true if there was an error during event processing
    // bool processEvents(sf::RenderWindow* window);

    // const EventListeners* getListener() const; 
    // EventListeners* getListener();

    // void resetTime();
  };

} // namespace DIM

#endif
