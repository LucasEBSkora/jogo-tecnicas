#include "MainMenu.hpp"
#include "../Managers/EventManager.hpp"
#include <iostream>

namespace DIM {
  namespace Menus {

    MainMenu::MainMenu() :  twoPlayers{true} {
      
    }

    MainMenu::~MainMenu() {

    }

    void MainMenu::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      Menu::init(g, e);
      Utils::VectorF viewsize = g.getViewSize();
      
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 9 * 1), 180, 30, 1, "New Temple Game"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 9 * 2), 220, 30, 2, "Load Last Temple Game"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 9 * 3), 180, 30, 3, "New Cavern Game"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 9 * 4), 220, 30, 4, "Load Last Cavern Game"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 9 * 6), 150, 30, 7, "Thread Level"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 9 * 7), 130, 30, 6, "Leaderboard"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 9 * 5), 190, 30, 5, "Number of Players:"));
      buttons.push_back(new Button(Utils::VectorF(viewsize.x / 2, viewsize.y / 9 * 8), 100, 30, 0, "Exit Game"));

      for (auto& b : buttons) {
        b->initialize(g);
      }
    }

    const int MainMenu::exec() {
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
                if (b->getId() != 5) {
                  return_val = b->getId();
                  keep_going = false;
                }
              }
            }
          } else if (e.getType() == Managers::EventManager::EventType::MouseButtonReleased) {
            Utils::VectorF pos = graphics->getMousePosInView();
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
        Utils::VectorF viewsize = graphics->getViewSize();
      
        graphics->drawTextCentered( ((twoPlayers) ? "2" : "1"), Utils::VectorF(viewsize.x * (1 + 0.3) / 2 , viewsize.y / 9 * 4.85) , 21 );
        graphics->display();
      }

      removeListeners();
      
      return return_val;
    }

    const bool MainMenu::useTwoPlayers() const {
      return twoPlayers;
    }

  }
}