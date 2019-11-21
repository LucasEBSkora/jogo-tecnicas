#include "Menu.hpp"

namespace DIM {
  namespace Menus {

    Menu::Menu() : graphics(nullptr) {
    }

    Menu::~Menu() {

    }

    void Menu::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      graphics = &g;
      events = &e;
    }

  }
}