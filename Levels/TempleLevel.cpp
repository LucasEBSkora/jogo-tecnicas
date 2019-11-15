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

  TempleLevel::TempleLevel() : Level(), keep_going(true), key_event_id(0) {
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
    player1->setLevel(nullptr);
    player2->setLevel(nullptr);
    player1 = nullptr;
    player2 = nullptr;
  }

  void TempleLevel::init(GraphicsManager& g, EventManager& e) {
    // std::cout << player2->getLevel() << std::endl;
    // if (player1 == nullptr) {
    //   std::cout << "tchauzinho" << std::endl;
    //   exit(321);
    // }
    Level::init(g, e);
    // std::cout << player2->getLevel() << std::endl;
    tileManager = new TileManager({
      new TempleWallTile(),
      new PlayerSpawnPoint(),
      new TempleSpikeObstacle(),
      new BulletObstacle()
    }, 32.0f, "assets/temple.tilemap");
    tileManager->setCurrentLevel(*this);
    entities.addEntity(tileManager);
    collisions.setTileManager(tileManager);
    // std::cout << player2->getLevel() << std::endl;
    // std::cout << player2->getLevel() << std::endl;
    // std::cout << player2->getLevel() << std::endl;
  }
  
  void TempleLevel::bindPlayers(Mob* p1, Mob* p2) {
    player1 = p1;
    player2 = p2;
    player1->setLevel(this);
    player2->setLevel(this);
    std::cout << player2->getLevel() << std::endl;
    entities.addEntity(player1);
    entities.addEntity(player2);
    collisions.addToCollisions(player1);
    collisions.addToCollisions(player2);
  }

  void TempleLevel::addPhysicalEntity(PhysicalEntity* ent) {
    ent->initializeGeneric(*graphics, *events);
    entities.addEntity(ent);
    collisions.addToCollisions(ent);
  }

  void TempleLevel::exec() {
    entities.initializeAll(*graphics, *events);
    player1->setPosition(tileManager->getPlayerSpawnPosition() + VectorF(32.0f, 32.0f) * .5 - player1->getSize() * .5);
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
      // graphics->clear(20, 20, 20);
      graphics->clear(200, 200, 200);
      graphics->centerCamera(getPlayer1Center());
      entities.updateAll(events->getLastElapsedTime());
      collisions.checkCollisions();
      entities.drawAll();
      graphics->display();
    }
  }

}