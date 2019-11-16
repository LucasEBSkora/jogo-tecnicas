#include "TempleLevel.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Entities/Players/ThePenitent.hpp"

#include "../Entities/Enemies/Leaper.hpp"
#include "../Entities/Enemies/Caster.hpp"

#include "../TileSystem/Tiles/TempleLevelTiles/BulletObstacle.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/GateToCavernTile.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/TempleSpikeObstacle.hpp"
#include "../TileSystem/Tiles/TempleLevelTiles/TempleWallTile.hpp"
#include "../TileSystem/Tiles/PlayerSpawnPoint.hpp"

#include "../RandomValueGenerator.hpp"
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
    tileManager->setLevel(this);
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
    ent->initializeGeneric(this);
    entities.addEntity(ent);
    collisions.addToCollisions(ent);
  }

  void TempleLevel::exec() {
    entities.initializeAll(this);
    player1->setPosition(tileManager->getPlayerSpawnPosition()  - player1->getSize() * .5);
    
    std::vector<VectorF> spawns = tileManager->getEnemySpawns();
    
    for (int i = 0; i < 5; ++i) {
      
      int idx = RandomValueGenerator::getInstance()->getRandomIntInRange(0, spawns.size());
      Enemy* enemy = new Leaper();
      enemy->setLevel(this);
      enemy->initializeGeneric(this);
      VectorF pos = spawns[idx] + VectorF(32.0f, 32.0f) * .5 - enemy->getSize() * .5;
      
      enemy->setPosition(VectorF(pos.x, pos.y));
      std::cout << idx << std::endl;
      entities.addEntity(enemy);
      collisions.addToCollisions(enemy);

      idx = RandomValueGenerator::getInstance()->getRandomIntInRange(0, spawns.size());
      enemy = new Caster();
      enemy->setLevel(this);
      enemy->initializeGeneric(this);
      pos = spawns[idx] + VectorF(32.0f, 32.0f) * .5 - enemy->getSize() * .5;
      
      enemy->setPosition(VectorF(pos.x, pos.y));
      std::cout << idx << std::endl;
      entities.addEntity(enemy);
      collisions.addToCollisions(enemy);
      

    }

    
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