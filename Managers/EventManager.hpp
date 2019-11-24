#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <map>
#include <functional>
#include <tuple>
#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"

namespace DIM {
  namespace Managers {

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
        TextEntered,
        MouseWheelScrolledUp,
        MouseWheelScrolledDown,
        MouseButtonPressed,
        MouseButtonReleased,
      };
      
      class Event {
      private:
        sf::Event event;
      public:
        Event();
        Event(sf::Event& ev);
        ~Event();

        void setEvent(sf::Event ev);

        const EventType getType() const;
        const MouseButton getMouseButton() const;
        const Key getKey() const;
        const char getChar() const;
      };

    private:
      Managers::GraphicsManager* graphics_manager;
      sf::Clock clock;
      
      sf::Time lastElapsedTime;

      static int next_uid;

      std::map<int, std::function<void(Event)>> keyboard_callbacks;
      std::map<int, std::function<void(Event)>> mouse_callbacks;

    public:
      EventManager();
      ~EventManager();

      void setGraphicsManager(Managers::GraphicsManager& manager);
      Managers::GraphicsManager* getGraphicsManager() const;
      
      int addKeyboardListener(std::function<void(Event)> callback);
      void removeKeyboardListener(int id);

      int addMouseListener(std::function<void(Event)> callback);
      void removeMouseListener(int id);

      void processEvents();

      float getLastElapsedTime() const;

    };
  }
}

#endif
