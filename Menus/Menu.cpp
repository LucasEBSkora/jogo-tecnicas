#include "Menu.hpp"

namespace DIM {
  namespace Menus {

    Menu::Menu() : graphics(nullptr), keep_going(true), key_event_id(0), mouse_event_id(0),
      return_val(0) {
    }

    Menu::~Menu() {
      removeListeners();
    }

    void Menu::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      graphics = &g;
      events = &e;
    }

    void Menu::removeListeners() {
      if (key_event_id != 0) {
        events->removeKeyboardListener(key_event_id);
        key_event_id = 0;
      }
      if (mouse_event_id != 0) {
        events->removeMouseListener(mouse_event_id);
        mouse_event_id = 0;
      }
    }
  }
}