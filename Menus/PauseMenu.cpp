#include "PauseMenu.hpp"

namespace DIM {
  namespace Menus {

    PauseMenu::PauseMenu() {
      
    }

    PauseMenu::~PauseMenu() {
      
    }

    void PauseMenu::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      Menu::init(g, e);
      Utils::VectorF viewsize = g.getViewSize();
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 4 * 1), 140, 30, 0, "Resume"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 4 * 2), 160, 30, 1, "Save Game"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 4 * 3), 160, 30, 2, "Main Menu"));

      for (auto& b : buttons) {
        b->initialize(g, e);
      }
    }

    const int PauseMenu::exec() {
      Utils::VectorF viewsize = graphics->getViewSize();
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
            Utils::VectorF pos = graphics->getMousePosInView();
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

      removeListeners();
      
      return return_val;
    }

  }
}