#ifndef PAUSEMENU_HPP
#define PAUSEMENU_HPP

#include "Menu.hpp"

namespace DIM {
  class PauseMenu : public Menu {
  private:
    bool keep_going;
    int key_event_id;
    int mouse_event_id;
    int return_val;
  public:
    PauseMenu();
    ~PauseMenu();

    void init(GraphicsManager& g, EventManager& e) override;

    int exec() override;
  };

}

#endif