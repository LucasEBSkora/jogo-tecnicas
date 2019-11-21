#include "TempleLevel.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Entities/Players/ThePenitent.hpp"


#include "../TileSystem/Tiles/TempleLevelTiles/BulletObstacle.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/GateToCavernTile.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/TempleSpikeObstacle.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/TempleWallTile.hpp"

#include "../TileSystem/Tiles/PlayerSpawnPoint.hpp"

#include "../Entities/Enemies/Leaper.hpp"
#include "../Entities/Enemies/Caster.hpp"

#include <iostream>


namespace DIM {
  namespace Levels {

    TempleLevel::TempleLevel() : Level("assets/TempleBackground.png"), key_event_id(0) {
      saveFilePath = "templeSave.txt";
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

    void TempleLevel::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      Level::init(g, e);
      tileManager = new Tile::TileManager({
        new Tile::TempleWallTile(),
        new Tile::PlayerSpawnPoint(),
        new Tile::TempleSpikeObstacle(),
        new Tile::BulletObstacle(),
        new Tile::GateToCavernTile()
      }, 32.0f, "assets/temple.tilemap");
      
      tileManager->setLevel(this);
      entities.addEntity(tileManager);
      collisions.setTileManager(tileManager);
      tileManager->initializeGeneric(this);

      key_event_id = events->addKeyboardListener(
        [this] (Managers::EventManager::Event e) {
          if (e.getType() == Managers::EventManager::EventType::KeyPressed &&
              e.getKey() == Managers::EventManager::Key::Escape) {
            decision = 0;
            keep_going = false;
          }
        }
      );
    }

  }
}