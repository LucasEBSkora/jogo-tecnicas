#include "CavernLevel.hpp"

#include "../TileSystem/Tiles/CavernLevelTiles/HoleObstacle.hpp"
#include "../TileSystem/Tiles/CavernLevelTiles/GameEndTile.hpp"
#include "../TileSystem/Tiles/CavernLevelTiles/CavernSpikeObstacle.hpp"
#include "../TileSystem/Tiles/CavernLevelTiles/CavernWallTile.hpp"

#include "../TileSystem/Tiles/PlayerSpawnPoint.hpp"

namespace DIM {

  CavernLevel::CavernLevel() : Level{"assets/CavernBackground.png"}, key_event_id{0} {
    
  }

  CavernLevel::~CavernLevel() {
    
    if (key_event_id != 0) {
      events->removeKeyboardListener(key_event_id);
      key_event_id = 0;
    }
    entities.removeWithoutDestroying(player1);
    entities.removeWithoutDestroying(player2);

    player1 = nullptr;
    player2 = nullptr;

  }


  void CavernLevel::init(GraphicsManager& g, EventManager& e) {
    Level::init(g, e);
    tileManager = new TileManager({
      new CavernWallTile(),
      new PlayerSpawnPoint(),
      new CavernSpikeObstacle(),
      new HoleObstacle(),
      new GameEndTile()
    }, 32.0f, "assets/cavern.tilemap");
    
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