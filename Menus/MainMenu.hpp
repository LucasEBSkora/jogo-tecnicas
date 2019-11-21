#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Menu.hpp"

namespace DIM {
  namespace Menus {
      
    class MainMenu : public Menu {
    private:
      bool keep_going;
      int key_event_id;
      int mouse_event_id;
      int return_val;
      bool twoPlayers;
    public:
      MainMenu();
      ~MainMenu();

      void init(Managers::GraphicsManager& g, Managers::EventManager& e) override;

      const int exec() override;

      const bool useTwoPlayers() const;
    };

  }
}

#endif