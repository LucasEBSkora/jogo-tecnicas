#ifndef MENU_HPP
#define MENU_HPP

#include "Button.hpp"
#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"
#include <vector>

namespace DIM {
  class Menu {
  protected:
    GraphicsManager* graphics;
    EventManager* events;
    std::vector<Button*> buttons;
  public:
    Menu();
    virtual ~Menu();

    virtual void init(GraphicsManager& g, EventManager& e);

    virtual const int exec() = 0;
  };

}

#endif