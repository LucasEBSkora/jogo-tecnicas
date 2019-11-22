#include "CavernLevel.hpp"

#include "../Tiles/Tile.hpp"

#include "../Entities/TheMirrorOfHastur.hpp"
#include "../Entities/Enemies/TheChained.hpp"



namespace DIM {
  namespace Levels {

    CavernLevel::CavernLevel() : Level{"assets/CavernBackground.png"}, key_event_id{0} {
      saveFilePath = "cavernSave.txt";
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


    void CavernLevel::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      Level::init(g, e);
      tileManager = new Tiles::TileManager({
        new Tiles::Tile("Wall", "assets/CavernWallTile.png"),
        new Tiles::Tile("Wall", "assets/PlayerSpawnPoint.png"),
        new Tiles::Tile("Spike", "assets/CavernSpikeObstacle.png"),
        new Tiles::Tile("Hole", "assets/HoleObstacle.png"),
        new Tiles::Tile("End", "assets/LevelEndTile.png")
      }, 32.0f, "assets/cavern.tilemap");
      
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

    void CavernLevel::playFromStart() {
      
      Level::playFromStart();

      Entities::TheMirrorOfHastur* ent = new Entities::TheMirrorOfHastur();

      Entities::TheChained* boss = new Entities::TheChained(ent);

      addPhysicalEntity(boss);
      addPhysicalEntity(ent);
    }

  }
}