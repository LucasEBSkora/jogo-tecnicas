#include "PauseMenu.hpp"

namespace DIM {
  namespace Menus {

    PauseMenu::PauseMenu() : keep_going(true), key_event_id(0), mouse_event_id(0) {
      
    }

    PauseMenu::~PauseMenu() {
      if (key_event_id != 0) {
        events->removeKeyboardListener(key_event_id);
        key_event_id = 0;
      }
      if (mouse_event_id != 0) {
        events->removeMouseListener(mouse_event_id);
        mouse_event_id = 0;
      }
    }

    void PauseMenu::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      Menu::init(g, e);
      Utility::VectorF viewsize = g.getViewSize();
      // o tamanho não deveria ser manual
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 4 * 1), 140, 30, 0, "Resume"));
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 4 * 2), 160, 30, 1, "Save Game"));
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 4 * 3), 160, 30, 2, "Main Menu"));

      for (auto& b : buttons) {
        b->initialize(g, e);
      }
    }

    const int PauseMenu::exec() {
      Utility::VectorF viewsize = graphics->getViewSize();
      graphics->centerCamera(viewsize * .5);
      keep_going = true;
      return_val = 0;

      key_event_id = events->addKeyboardListener(
        [this] (Managers::EventManager::Event e) {
          if (e.getType() == Managers::EventManager::EventType::KeyPressed &&
              e.getKey() == Managers::EventManager::Key::Escape) {
            keep_going = false;
          }
        }
      );
      mouse_event_id = events->addMouseListener(
        [this] (Managers::EventManager::Event e) {
          if (e.getType() == Managers::EventManager::EventType::MouseButtonPressed) {
            Utility::VectorF pos = graphics->getMousePosInView();
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

      if (key_event_id != 0) {
        events->removeKeyboardListener(key_event_id);
        key_event_id = 0;
      }
      if (mouse_event_id != 0) {
        events->removeMouseListener(mouse_event_id);
        mouse_event_id = 0;
      }

      return return_val;
    }

  }
}