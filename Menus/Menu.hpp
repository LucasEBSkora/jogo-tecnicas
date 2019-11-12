#ifndef MENU_HPP
#define MENU_HPP

#include "Button.hpp"
#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"
#include "../Lists/EntityList.hpp"

namespace DIM {
  class Menu {
  protected:
    GraphicsManager* graphics;
    EventManager events;
    EntityList entities;
  public:
    Menu();
    virtual ~Menu();

    virtual void init(GraphicsManager* g);

    virtual void exec() = 0;
  };

}

#endif