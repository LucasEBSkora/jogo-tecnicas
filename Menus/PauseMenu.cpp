#include "PauseMenu.hpp"

namespace DIM {

  PauseMenu::PauseMenu() : keep_going(true), key_event_id(0), mouse_event_id(0) {
    
  }

  PauseMenu::~PauseMenu() {
    if (key_event_id != 0) {
      events->removeKeyboardListener(key_event_id);
      key_event_id = 0;
    }
    if (mouse_event_id != 0) {
      events->removeKeyboardListener(mouse_event_id);
      mouse_event_id = 0;
    }
  }

  void PauseMenu::init(GraphicsManager& g, EventManager& e) {
    Menu::init(g, e);
    VectorF viewsize = g.getViewSize();
    keep_going = true;
    return_val = 0;
    // o tamanho não deveria ser manual
    buttons.push_back(new Button(viewsize.x / 2, viewsize.y / 4 * 1, 140, 30, 0, "Resume"));
    buttons.push_back(new Button(viewsize.x / 2, viewsize.y / 4 * 2, 160, 30, 1, "Save Game"));
    buttons.push_back(new Button(viewsize.x / 2, viewsize.y / 4 * 3, 160, 30, 2, "Main Menu"));
    g.centerCamera(viewsize * .5);

    for (auto& b : buttons) {
      b->initialize(g, e);
    }
  }

  int PauseMenu::exec() {
    key_event_id = events->addKeyboardListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::KeyPressed &&
            e.getKey() == EventManager::Key::Escape) {
          keep_going = false;
        }
      }
    );
    mouse_event_id = events->addMouseListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::MouseButtonPressed) {
          VectorF pos = graphics->getMousePosInView();
          for (auto& b : buttons) {
            if (b->isInside(pos)) {
              return_val = b->getId();
              keep_going = false;
            }
          }
        }
      }
    );
    while (keep_going) {
      events->processEvents();
      graphics->clear(20, 20, 20);
      for (auto& b : buttons) b->draw();
      graphics->display();
    }
    return return_val;
  }

}