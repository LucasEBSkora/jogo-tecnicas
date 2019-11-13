#include "TempleLevel.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Entities/Players/ThePenitent.hpp"

#include "../TileSystem/Tiles/TempleLevelTiles/BulletObstacle.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/GateToCavernTile.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/TempleSpikeObstacle.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/TempleWallTile.hpp"
#include "../TileSystem/Tiles/PlayerSpawnPoint.hpp"
#include <iostream>

namespace DIM {

  TempleLevel::TempleLevel(Mob* p1, Mob* p2) : Level(p1, p2), keep_going(true), key_event_id(0) {
  
  }

  TempleLevel::~TempleLevel() {
    if (key_event_id != 0) {
      events->removeKeyboardListener(key_event_id);
      key_event_id = 0;
    }
    entities.removeWithoutDestroying(player1);
    entities.removeWithoutDestroying(player2);
    player1 = nullptr;
    player2 = nullptr;
  }

  void TempleLevel::init(GraphicsManager& g, EventManager& e) {
    if (player1 == nullptr) {
      std::cout << "tchauzinho" << std::endl;
      exit(321);
    }
    Level::init(g, e);
    tileManager = new TileManager({
      TempleWallTile(),
      PlayerSpawnPoint(),
      TempleSpikeObstacle(),
      
    }, 32.0f, "assets/temple.tilemap");
    entities.addEntity(tileManager);
    entities.addEntity(player1);
    entities.addEntity(player2);
    entities.initializeAll(*graphics, *events);
  }

  void TempleLevel::exec() {
    key_event_id = events->addKeyboardListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::KeyPressed &&
            e.getKey() == EventManager::Key::Escape) {
          keep_going = false;
        }
      }
    );
    while (keep_going) {
      events->processEvents();
      graphics->clear(20, 20, 20);
      // graphics->centerCamera(main_player->getPosition());
      entities.updateAll(events->getLastElapsedTime());
      entities.drawAll();
      graphics->display();
    }
  }

}