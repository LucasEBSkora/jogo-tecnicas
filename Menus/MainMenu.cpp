#include "MainMenu.hpp"
#include "../EventManager.hpp" // Menu.hpp já inclui. por que inclui aqui de novo? n sei

namespace DIM {

  MainMenu::MainMenu() : keep_going(true), event_id(0) {
    
  }

  MainMenu::~MainMenu() {
    if (event_id != 0) {
      events.removeKeyboardListener(event_id);
      event_id = 0;
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
    event_id = events.addKeyboardListener([this] (EventManager::Key k, EventManager::EventType t) {keep_going = false; });
    while (keep_going) {
      events.processEvents();
      graphics->clear(80, 80, 80);

      entities.drawAll();
      graphics->display();
    }
  }

}