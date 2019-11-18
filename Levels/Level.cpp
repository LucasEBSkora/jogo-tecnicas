#include "Level.hpp"

#include <iostream>

#include "../RandomValueGenerator.hpp"

#include "../Entities/Enemies/Leaper.hpp"
#include "../Entities/Enemies/Caster.hpp"



namespace DIM {

  Level::Level(const std::string background) : graphics(nullptr), events(nullptr), player1(nullptr),
    player2(nullptr), tileManager(nullptr), decision{0}, keep_going{true}, backgroundPath{background} {
    
  }

  Level::~Level() {

  }

  void Level::init(GraphicsManager& g, EventManager& e) {
    graphics = &g;
    events = &e;
    graphics->loadAsset(backgroundPath);
  }

  const VectorF Level::getPlayer1Center() const {
    if (player1 == nullptr) std::cout << "segfaulting agora" << std::endl;
    return player1->getPos() + player1->getSize() * .5;
  }

  const VectorF Level::getPlayer1Spawn() const {
    return tileManager->getPlayerSpawnPosition() - player1->getSize() * .5;
  }

  CollisionManager* Level::getCollisionManager() { 
    return &collisions;
  }

  EventManager* Level::getEventManager() const{ 
    return events;
  }
  
  GraphicsManager* Level::getGraphicsManager() const {
    return graphics;
  }

  void Level::markForDelete(PhysicalEntity* ent) {
    markedToDelete.insert(ent);
  }

  void Level::endLevel() {
    decision = 1;
    keep_going = false;
  }

  void Level::generateEnemies() {
    std::vector<VectorF> spawns = tileManager->getEnemySpawns();
    int nEnemies = RandomValueGenerator::getInstance()->getRandomIntInRange(5, 10);
    
    for (int i = 0; i < nEnemies; ++i) {
      
      int idx = RandomValueGenerator::getInstance()->getRandomIntInRange(0, spawns.size());
      Enemy* enemy = new Leaper();
      enemy->setLevel(this);
      enemy->initializeGeneric(this);
      VectorF pos = spawns[idx] + VectorF(32.0f, 32.0f) * .5 - enemy->getSize() * .5;

      enemy->setPosition(VectorF(pos.x, pos.y));
      entities.addEntity(enemy);
      collisions.addToCollisions(enemy);

      idx = RandomValueGenerator::getInstance()->getRandomIntInRange(0, spawns.size());
      enemy = new Caster();
      enemy->setLevel(this);
      enemy->initializeGeneric(this);
      pos = spawns[idx] + VectorF(32.0f, 32.0f) * .5 - enemy->getSize() * .5;
      
      enemy->setPosition(VectorF(pos.x, pos.y));
      // std::cout << idx << std::endl;
      entities.addEntity(enemy);
      collisions.addToCollisions(enemy);

    }
  }

  void Level::addPhysicalEntity(PhysicalEntity* ent) {
    ent->initializeGeneric(this);
    entities.addEntity(ent);
    collisions.addToCollisions(ent);
  }

  void Level::setPlayers(TheUndying* p1, ThePenitent* p2) {
    
    player1 = p1;
    if (p2 == nullptr) {
      entities.removeWithoutDestroying(player2);
      collisions.removeFromCollisions(player2);
    }
    player2 = p2;
    
  }

  void Level::playFromStart() {
    if (player1 == nullptr) {
      throw 'k';
    }
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

    generateEnemies();

  }

  int Level::exec() {
    keep_going = true;
    while (keep_going) {
      
      for ( PhysicalEntity* ent : markedToDelete) {

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
      graphics->display();
    }
    return decision;
  }
}