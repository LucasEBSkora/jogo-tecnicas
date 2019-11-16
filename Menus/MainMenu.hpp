#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Menu.hpp"

namespace DIM {
  class MainMenu : public Menu {
  private:
    bool keep_going;
    int key_event_id;
    int mouse_event_id;
    int return_val;
  public:
    MainMenu();
    ~MainMenu();

    void init(GraphicsManager& g, EventManager& e) override;

    int exec() override;
  };

}

#endif