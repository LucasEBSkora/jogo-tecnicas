#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Menu.hpp"

namespace DIM {
  namespace Menus {
      
    class MainMenu : public Menu {
    private:

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