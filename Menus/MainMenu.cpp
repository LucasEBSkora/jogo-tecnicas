#include "MainMenu.hpp"
#include "../EventManager.hpp" // Menu.hpp já inclui. por que inclui aqui de novo? n sei
#include <iostream>

namespace DIM {

  MainMenu::MainMenu() : keep_going(true), key_event_id(0), mouse_event_id(0),
    return_val(0) {
    
  }

  MainMenu::~MainMenu() {
    if (key_event_id != 0) {
      events->removeKeyboardListener(key_event_id);
      key_event_id = 0;
    }
    if (mouse_event_id != 0) {
      events->removeKeyboardListener(mouse_event_id);
      mouse_event_id = 0;
    }
  }

  void MainMenu::init(GraphicsManager& g, EventManager& e) {
    Menu::init(g, e);
    VectorF viewsize = g.getViewSize();
    keep_going = true;
    return_val = 0;
    // o tamanho não deveria ser manual
    entities.addEntity(new Button(viewsize.x / 2, viewsize.y / 6 * 1, 180, 30, 1, "New Temple Game"));
    entities.addEntity(new Button(viewsize.x / 2, viewsize.y / 6 * 2, 220, 30, 2, "Load Last Temple Game"));
    entities.addEntity(new Button(viewsize.x / 2, viewsize.y / 6 * 3, 180, 30, 3, "New Cavern Game"));
    entities.addEntity(new Button(viewsize.x / 2, viewsize.y / 6 * 4, 220, 30, 4, "Load Last Cavern Game"));
    entities.addEntity(new Button(viewsize.x / 2, viewsize.y / 6 * 5, 100, 30, 0, "Exit Game"));
    g.centerCamera(viewsize * .5);

    entities.initializeAll(g, e);
  }

  int MainMenu::exec() {
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
          std::cout << "mouse at " << pos.x << ' ' << pos.y << std::endl;
          for (EntityList::iterator i = entities.begin();
              i != entities.end();
              ++i) {
            std::cout << "bom dia" << static_cast<Button*>(*i)->isInside(pos) << std::endl;
            if (static_cast<Button*>(*i)->isInside(pos)) {
              return_val = static_cast<Button*>(*i)->getId();
              keep_going = false;
            }
          }
        }
      }
    );
    while (keep_going) {
      events->processEvents();
      graphics->clear(20, 20, 20);
      entities.updateAll(events->getLastElapsedTime());
      entities.drawAll();
      graphics->display();
    }
    return return_val;
  }

}