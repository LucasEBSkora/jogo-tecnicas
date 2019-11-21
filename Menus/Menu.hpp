#ifndef MENU_HPP
#define MENU_HPP

#include "Button.hpp"
#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"
#include <vector>

namespace DIM {
  namespace Menus {
      
    class Menu {
    protected:
      Managers::GraphicsManager* graphics;
      Managers::EventManager* events;
      std::vector<Button*> buttons;
    public:
      Menu();
      virtual ~Menu();

      virtual void init(Managers::GraphicsManager& g, Managers::EventManager& e);

      virtual const int exec() = 0;
    };

  }
}

#endif