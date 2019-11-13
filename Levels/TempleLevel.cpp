#include "TempleLevel.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Entities/Players/ThePenitent.hpp"

#include "../TileSystem/Tiles/TempleLevelTiles/BulletObstacle.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/GateToCavernTile.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/TempleSpikeObstacle.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/TempleWallTile.hpp"
#include "../TileSystem/Tiles/PlayerSpawnPoint.hpp"


namespace DIM {

  TempleLevel::TempleLevel() : keep_going(true), key_event_id(0) {
  
  }

  TempleLevel::~TempleLevel() {
    if (key_event_id != 0) {
      events.removeKeyboardListener(key_event_id);
      key_event_id = 0;
    }
    delete main_player;
    delete tileManager;
  }

  void TempleLevel::init(GraphicsManager* g) {
    Level::init(g);
    tileManager = new TileManager({
      TempleWallTile(),
      PlayerSpawnPoint(),
      TempleSpikeObstacle(),
      
    }, 32.0f, "assets/temple.tilemap");
    entities.addEntity(tileManager);
    main_player = new TheUndying();
    entities.addEntity(main_player);
    entities.initializeAll(graphics, &events);
  }

  void TempleLevel::exec() {
    key_event_id = events.addKeyboardListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::KeyPressed &&
            e.getKey() == EventManager::Key::Escape) {
          keep_going = false;
        }
      }
    );
    while (keep_going) {
      events.processEvents();
      graphics->clear(20, 20, 20);
      // graphics->centerCamera(main_player->getPosition());
      entities.updateAll(events.getLastElapsedTime());
      entities.drawAll();
      graphics->display();
    }
  }

}