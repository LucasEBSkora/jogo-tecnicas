#include "Menu.hpp"

namespace DIM {

  Menu::Menu() : graphics(nullptr) {
  }

  Menu::~Menu() {

  }

  void Menu::init(GraphicsManager& g, EventManager& e) {
    graphics = &g;
    events = &e;
  }

}