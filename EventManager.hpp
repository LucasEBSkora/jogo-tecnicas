#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <map>
#include <functional>
#include <tuple>
#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"

namespace DIM {

  class EventManager {
  public:
    enum class Key {
      Unknown = -1,
      A = 0,
      B,
      C,
      D,
      E,
      F,
      G,
      H,
      I,
      J,
      K,
      L,
      M,
      N,
      O,
      P,
      Q,
      R,
      S,
      T,
      U,
      V,
      W,
      X,
      Y,
      Z,
      Num0,
      Num1,
      Num2,
      Num3,
      Num4,
      Num5,
      Num6,
      Num7,
      Num8,
      Num9,
      Escape,
      LControl,
      LShift,
      LAlt,
      LSystem,
      RControl,
      RShift,
      RAlt,
      RSystem,
      Menu,
      LBracket,
      RBracket,
      Semicolon,
      Comma,
      Period,
      Quote,
      Slash,
      Backslash,
      Tilde,
      Equal,
      Hyphen,
      Space,
      Enter,
      Backspace,
      Tab,
      PageUp,
      PageDown,
      End,
      Home,
      Insert,
      Delete,
      Add,
      Subtract,
      Multiply,
      Divide,
      Left,
      Right,
      Up,
      Down,
      Numpad0,
      Numpad1,
      Numpad2,
      Numpad3,
      Numpad4,
      Numpad5,
      Numpad6,
      Numpad7,
      Numpad8,
      Numpad9,
      F1,
      F2,
      F3,
      F4,
      F5,
      F6,
      F7,
      F8,
      F9,
      F10,
      F11,
      F12,
      F13,
      F14,
      F15,
      Pause,
    };

    enum class MouseButton {
      Left,
      Right,
      Middle,
    };

    enum class EventType {
      Other = -1,
      KeyPressed = 0,
      KeyReleased,
      MouseWheelScrolled,
      MouseButtonPressed,
      MouseButtonReleased,
    };
    // tá quase virando um sf::Event
    class Event {
    private:
      sf::Event event;
    public:
      Event();
      Event(sf::Event& ev);
      ~Event();

      void setEvent(sf::Event ev);

      EventType getType() const;
      MouseButton getMouseButton() const;
      Key getKey() const;
    };

  private:
    GraphicsManager* graphics_manager;
    sf::Clock clock;

    //inverse of framerate, basically
    // static const sf::Time timePerFrame;

    //time since last processEvents() call
    // sf::Time timeSinceLastUpdate;
    sf::Time lastElapsedTime;

    //Vector of time values used to keep track of timers with different periods
    // std::vector<sf::Time> timers;
    static int next_uid;

    std::map<int, std::tuple<sf::Time, sf::Time, std::function<void()>>> timers_callbacks;
    std::map<int, std::function<void(Event)>> keyboard_callbacks;
    std::map<int, std::function<void(Event)>> mouse_callbacks;

  public:
    EventManager();
    ~EventManager();

    void setGraphicsManager(GraphicsManager& manager);
    GraphicsManager* getGraphicsManager() const;
    
    int addTimer(float seconds, std::function<void()> callback);
    void removeTimer(int id);

    int addKeyboardListener(std::function<void(Event)> callback);
    void removeKeyboardListener(int id);

    int addMouseListener(std::function<void(Event)> callback);
    void removeMouseListener(int id);

    void processEvents();

    //returns true if there was an error during event processing
    // bool processEvents(sf::RenderWindow* window);

    // const EventListeners* getListener() const; 
    // EventListeners* getListener();
    float getLastElapsedTime() const;

    void resetTime();
  };

} // namespace DIM

#endif
