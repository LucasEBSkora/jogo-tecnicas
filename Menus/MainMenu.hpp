#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Menu.hpp"

namespace DIM {
  class MainMenu : public Menu {
  private:
    bool keep_going;
    int event_id;
  public:
    MainMenu();
    ~MainMenu();

    void init(GraphicsManager* g) override;

    void exec() override;
  };

}

#endif