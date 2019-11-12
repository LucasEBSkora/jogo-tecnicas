#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Menu.hpp"

namespace DIM {
  class MainMenu : public Menu {
  private:
    bool keep_going;
    int key_event_id;
    int mouse_event_id;
  public:
    MainMenu();
    ~MainMenu();

    void init(GraphicsManager* g) override;

    void exec() override;
  };

}

#endif