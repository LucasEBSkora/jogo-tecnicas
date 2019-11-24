#ifndef MENU_HPP
#define MENU_HPP

#include "Button.hpp"
#include "../Managers/GraphicsManager.hpp"
#include "../Managers/EventManager.hpp"
#include <vector>

namespace DIM {
  namespace Menus {
      
    class Menu {
    protected:
      Managers::GraphicsManager* graphics;
      Managers::EventManager* events;
      std::vector<Button*> buttons;
      bool keep_going;
      int key_event_id;
      int mouse_event_id;
      int return_val;
      
    public:
      Menu();
      virtual ~Menu();

      virtual void init(Managers::GraphicsManager& g, Managers::EventManager& e);
      
      void removeListeners();
      virtual const int exec() = 0;
    };

  }
}

#endif