#include "MainMenu.hpp"
#include "../EventManager.hpp" // Menu.hpp já inclui. por que inclui aqui de novo? n sei
#include <iostream>

namespace DIM {

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

  void MainMenu::init(GraphicsManager& g, EventManager& e) {
    Menu::init(g, e);
    VectorF viewsize = g.getViewSize();
    // o tamanho não deveria ser manual
    buttons.push_back(new Button(VectorF(viewsize.x / 2, viewsize.y / 7 * 1), 180, 30, 1, "New Temple Game"));
    buttons.push_back(new Button(VectorF(viewsize.x / 2, viewsize.y / 7 * 2), 220, 30, 2, "Load Last Temple Game"));
    buttons.push_back(new Button(VectorF(viewsize.x / 2, viewsize.y / 7 * 3), 180, 30, 3, "New Cavern Game"));
    buttons.push_back(new Button(VectorF(viewsize.x / 2, viewsize.y / 7 * 4), 220, 30, 4, "Load Last Cavern Game"));
    buttons.push_back(new Button(VectorF(viewsize.x / 2, viewsize.y / 7 * 5), 100, 30, 0, "Exit Game"));
    buttons.push_back(new Button(VectorF(viewsize.x / 2, viewsize.y / 7 * 6), 190, 30, 5, "Number of Players:"));

    for (auto& b : buttons) {
      b->initialize(g, e);
    }
  }

  const int MainMenu::exec() {
    VectorF viewsize = graphics->getViewSize();
    graphics->centerCamera(viewsize * .5);
    keep_going = true;
    return_val = 0;

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
          // std::cout << "mouse at " << pos.x << ' ' << pos.y << std::endl;
          for (auto& b : buttons) {
            if (b->isInside(pos)) {
              if (b->getId() != 5) {
                return_val = b->getId();
                keep_going = false;
              }
            }
          }
        } else if (e.getType() == EventManager::EventType::MouseButtonReleased) {
          VectorF pos = graphics->getMousePosInView();
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
      VectorF viewsize = graphics->getViewSize();
      //std::cout << twoPlayers  << std::endl;
    
      graphics->drawTextCentered( ((twoPlayers) ? "2" : "1"), VectorF(viewsize.x * (1 + 0.3) / 2 , viewsize.y / 7 * 5.9) , 21 );
      graphics->display();
    }

    if (key_event_id != 0) {
      events->removeKeyboardListener(key_event_id);
      key_event_id = 0;
    }
    // std::cout << mouse_event_id << std::endl;
    if (mouse_event_id != 0) {
      events->removeMouseListener(mouse_event_id);
      mouse_event_id = 0;
    }
    // std::cout << mouse_event_id << std::endl;
    
    return return_val;
  }

  const bool MainMenu::useTwoPlayers() const {
    return twoPlayers;
  }

}