#include "MainMenu.hpp"
#include "../EventManager.hpp"
#include <iostream>

namespace DIM {
  namespace Menus {

    MainMenu::MainMenu() : keep_going(true), key_event_id(0), mouse_event_id(0),
      return_val(0), twoPlayers{true} {
      
    }

    MainMenu::~MainMenu() {
      if (key_event_id != 0) {
        events->removeKeyboardListener(key_event_id);
        key_event_id = 0;
      }
      if (mouse_event_id != 0) {
        events->removeMouseListener(mouse_event_id);
        mouse_event_id = 0;
      }
    }

    void MainMenu::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      Menu::init(g, e);
      Utility::VectorF viewsize = g.getViewSize();
      
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 8 * 1), 180, 30, 1, "New Temple Game"));
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 8 * 2), 220, 30, 2, "Load Last Temple Game"));
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 8 * 3), 180, 30, 3, "New Cavern Game"));
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 8 * 4), 220, 30, 4, "Load Last Cavern Game"));
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 8 * 5), 220, 30, 6, "Extra Level (Threaded)"));
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 8 * 6), 100, 30, 0, "Exit Game"));
      buttons.push_back(new Button(Utility::VectorF(viewsize.x / 2, viewsize.y / 8 * 7), 190, 30, 5, "Number of Players:"));

      for (auto& b : buttons) {
        b->initialize(g, e);
      }
    }

    const int MainMenu::exec() {
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
                if (b->getId() != 5) {
                  return_val = b->getId();
                  keep_going = false;
                }
              }
            }
          } else if (e.getType() == Managers::EventManager::EventType::MouseButtonReleased) {
            Utility::VectorF pos = graphics->getMousePosInView();
            for (auto& b : buttons) {
              if (b->isInside(pos)) {
                if (b->getId() == 5) {
                  twoPlayers = !twoPlayers;
                } 
              }
            }
          }
        }
      );

      while (keep_going) {
        events->processEvents();
        graphics->clear(20, 20, 20);
        for (auto& b : buttons) b->draw();
        Utility::VectorF viewsize = graphics->getViewSize();
      
        graphics->drawTextCentered( ((twoPlayers) ? "2" : "1"), Utility::VectorF(viewsize.x * (1 + 0.3) / 2 , viewsize.y / 8 * 6.9) , 21 );
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

    const bool MainMenu::useTwoPlayers() const {
      return twoPlayers;
    }

  }
}