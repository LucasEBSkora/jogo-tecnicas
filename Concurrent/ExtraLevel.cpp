#include "ExtraLevel.hpp"

#include "../TileSystem/Tiles/CavernLevelTiles/HoleObstacle.hpp"
#include "../TileSystem/Tiles/CavernLevelTiles/GameEndTile.hpp"
#include "../TileSystem/Tiles/CavernLevelTiles/CavernSpikeObstacle.hpp"
#include "../TileSystem/Tiles/CavernLevelTiles/CavernWallTile.hpp"

#include "../TileSystem/Tiles/PlayerSpawnPoint.hpp"

#include "../RandomValueGenerator.hpp"

#include <iterator>

namespace DIM {
  namespace Concurrent {

    ExtraLevel::ExtraLevel() : Levels::Level{"assets/CavernBackground.png"}, key_event_id{0} {
        
    }

    ExtraLevel::~ExtraLevel() {
      if (key_event_id != 0) {
        events->removeKeyboardListener(key_event_id);
        key_event_id = 0;
      }
      entities.removeWithoutDestroying(player1);
      entities.removeWithoutDestroying(player2);

      player1 = nullptr;
      player2 = nullptr; 
    }

    void ExtraLevel::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      Level::init(g, e);
      tileManager = new Tile::TileManager({
        new Tile::CavernWallTile(),
        new Tile::PlayerSpawnPoint(),
        new Tile::CavernSpikeObstacle(),
        new Tile::HoleObstacle(),
        new Tile::GameEndTile()
      }, 32.0f, "assets/extralevel.tilemap");
      
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

    void ExtraLevel::playFromStart() {
      if (player1 == nullptr) {
        throw 'k';
      }
      tileManager->regenRandomTiles();
      entities.removeWithoutDestroying(tileManager);
      entities.removeWithoutDestroying(player1);
      entities.removeWithoutDestroying(player2);
      entities.destroyAll();
      collisions.removeAll();
      entities.addEntity(tileManager);

      entities.addEntity(player1);
      collisions.addToCollisions(player1);
      
      if (player2 != nullptr) {
        entities.addEntity(player2);
        collisions.addToCollisions(player2);
      }

      player1->setPosition(getPlayer1Spawn());

      std::vector<Utility::VectorF> spawns = tileManager->getEnemySpawns();
      int n_casters = std::min(static_cast<int>(spawns.size()), 4);

      for (int i = 0; i < n_casters; ++i) {
        int idx = Utility::RandomValueGenerator::getInstance()->getRandomIntInRange(0, spawns.size());
        casters.push_back(new ThreadedCaster(spawns[idx]));
        spawns.erase(std::next(spawns.begin(), idx));
      }

      for (auto& c : casters) c->initializeGeneric(this);
      for (auto& c : casters) c->setPaused(true);
      // for (auto& c : casters) c->stopRunning();
      // for (auto& c : casters) c->join();
      for (auto& c : casters) c->start();
    }

    int ExtraLevel::exec() {
      keep_going = true;
      for (auto& c : casters) c->setPaused(false);
      while (keep_going) {
        
        for (Entities::PhysicalEntity* ent : markedToDelete) {

          entities.removeWithoutDestroying(ent);
          collisions.removeFromCollisions(ent);
          delete ent;

        }
        markedToDelete.clear();
      
        events->processEvents();
        graphics->clear(200, 200, 200);
        graphics->centerCamera(getPlayer1Center());
        graphics->draw(backgroundPath, getPlayer1Center() - graphics->getSizeOfAsset(backgroundPath) * 0.5);
        entities.updateAll(events->getLastElapsedTime());
        collisions.checkCollisions();
        entities.drawAll();
        for (auto& c : casters) c->draw();
        graphics->display();
      }

      for (Entities::PhysicalEntity* ent : markedToDelete) {

        entities.removeWithoutDestroying(ent);
        collisions.removeFromCollisions(ent);
        delete ent;

      }
      markedToDelete.clear();

      for (auto& c : casters) c->setPaused(true);
      return decision;
    }

  }
}
