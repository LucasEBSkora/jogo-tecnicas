#include "TempleLevel.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Entities/Players/ThePenitent.hpp"
// #include "../TileSystem/TileManager.hpp" // Usar tilemanager

namespace DIM {

  TempleLevel::TempleLevel() : keep_going(true), key_event_id(0) {
    
  }

  TempleLevel::~TempleLevel() {
    if (key_event_id != 0) {
      events.removeKeyboardListener(key_event_id);
      key_event_id = 0;
    }
  }

  void TempleLevel::init(GraphicsManager* g) {
    Level::init(g);
    // TileManager t;
    // entities.addEntity(&t);
    main_player = new TheUndying();
    entities.addEntity(main_player);
    entities.initializeAll(graphics, &events);
  }

  void TempleLevel::exec() {
    key_event_id = events.addKeyboardListener(
      [this] (EventManager::Key k, EventManager::EventType t) {
        if (k == EventManager::Key::Esc) {
          keep_going = false;
        }
      }
    );
    while (keep_going) {
      events.processEvents();
      graphics->clear(20, 20, 20);
      entities.updateAll(events.getLastElapsedTime());
      entities.drawAll();
      graphics->display();
    }
  }

}