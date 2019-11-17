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

  TempleLevel::TempleLevel() : Level("assets/TempleBackground.png"), key_event_id(0) {
    // player1->setLevel(this);
    // player2->setLevel(this);
    // std::cout << player2->getLevel() << std::endl;
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
    Level::init(g, e);
    tileManager = new TileManager({
      new TempleWallTile(),
      new PlayerSpawnPoint(),
      new TempleSpikeObstacle(),
      new BulletObstacle(),
      new GateToCavernTile()
    }, 32.0f, "assets/temple.tilemap");
    
    tileManager->setLevel(this);
    entities.addEntity(tileManager);
    collisions.setTileManager(tileManager);
    tileManager->initializeGeneric(this);

    key_event_id = events->addKeyboardListener(
      [this] (EventManager::Event e) {
        if (e.getType() == EventManager::EventType::KeyPressed &&
            e.getKey() == EventManager::Key::Escape) {
          keep_going = false;
        }
      }
    );
  }

}