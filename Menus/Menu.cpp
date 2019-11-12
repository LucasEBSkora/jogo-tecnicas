#include "Menu.hpp"

namespace DIM {

  Menu::Menu() : graphics(nullptr) {
  }

  Menu::~Menu() {

  }

  void Menu::init(GraphicsManager* g) { // talvez mudar pra parâmetro por referência
    graphics = g;
    events.setGraphicsManager(graphics);
  }

}