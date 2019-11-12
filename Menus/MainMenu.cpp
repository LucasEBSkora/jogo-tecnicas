#include "MainMenu.hpp"
#include "../EventManager.hpp" // Menu.hpp já inclui. por que inclui aqui de novo? n sei

namespace DIM {

  MainMenu::MainMenu() : keep_going(true), key_event_id(0), mouse_event_id(0) {
    
  }

  MainMenu::~MainMenu() {
    if (key_event_id != 0) {
      events.removeKeyboardListener(key_event_id);
      key_event_id = 0;
    }
    if (mouse_event_id != 0) {
      events.removeKeyboardListener(mouse_event_id);
      mouse_event_id = 0;
    }
  }

  void MainMenu::init(GraphicsManager* g) {
    Menu::init(g);
    VectorF viewsize = graphics->getViewSize();
    entities.addEntity(new Button(viewsize.x / 2, viewsize.y / 2, 50, 30));
    entities.addEntity(new Button(viewsize.x / 2, viewsize.y / 2 + 100, 80, 25));

    entities.inicializeAll(graphics);
  }

  void MainMenu::exec() {
    key_event_id = events.addKeyboardListener(
      [this] (EventManager::Key k, EventManager::EventType t) {
        keep_going = false;
      }
    );
    // mouse_event_id = events.addMouseListener(
    //   [this] (EventManager::Button b, EventManager::EventType t) {
    //     VectorF pos = graphics->getMousePos();
    //     for (EntityList::iterator i = entities.begin();
    //          i != entities.end();
    //          ++i) {
    //       // if ()
    //     }
    //   }
    // );
    while (keep_going) {
      events.processEvents();
      graphics->clear(20, 20, 20);
      entities.updateAll(events.getLastElapsedTime());
      entities.drawAll();
      graphics->display();
    }
  }

}