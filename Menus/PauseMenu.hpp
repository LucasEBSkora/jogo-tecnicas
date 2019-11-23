#ifndef PAUSEMENU_HPP
#define PAUSEMENU_HPP

#include "Menu.hpp"

namespace DIM {
  namespace Menus {
      
    class PauseMenu : public Menu {
    private:
    public:
      PauseMenu();
      ~PauseMenu();

      void init(Managers::GraphicsManager& g, Managers::EventManager& e) override;

      const int exec() override;
    };

  }
}

#endif