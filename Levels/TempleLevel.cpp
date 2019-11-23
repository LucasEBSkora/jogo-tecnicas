#include "TempleLevel.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Entities/Players/ThePenitent.hpp"

#include "../Tiles/Tile.hpp"
#include "../Tiles/BulletObstacle.hpp"

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
      tileManager = new Tiles::TileManager({
        new Tiles::Tile("Wall", "assets/TempleWallTile.png"),
        new Tiles::Tile("Wall", "assets/PlayerSpawnPoint.png"),
        new Tiles::Tile("Spike", "assets/TempleSpikeObstacle.png"),
        new Tiles::BulletObstacle(),
        new Tiles::Tile("End", "assets/LevelEndTile.png")
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