#include "Level.hpp"

#include <iostream>
#include <fstream>

#include "../RandomValueGenerator.hpp"

#include "../Entities/Enemies/Leaper.hpp"
#include "../Entities/Enemies/Caster.hpp"

#include "../Entities/Enemies/TheChained.hpp"
#include "../Entities/TheMirrorOfHastur.hpp"
#include "../Entities/Projectiles/Bullet.hpp"
#include "../Entities/Projectiles/Spell.hpp"

namespace DIM {
  namespace Levels {

    Level::Level(const std::string background) : graphics(nullptr), events(nullptr), player1(nullptr),
      player2(nullptr), tileManager(nullptr), decision{0}, keep_going{true}, backgroundPath{background},
      saveFilePath{} {
      
    }

    Level::~Level() {

    }

    void Level::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
      graphics = &g;
      events = &e;
      graphics->loadAsset(backgroundPath);
    }

    const Utils::VectorF Level::getPlayer1Center() const {
      if (player1 == nullptr) std::cout << "segfaulting agora" << std::endl;
      return player1->getPos() + player1->getSize() * .5;
    }

    const Utils::VectorF Level::getPlayer1Spawn() const {
      return tileManager->getPlayerSpawnPosition() - player1->getSize() * .5;
    }

    const Utils::VectorF Level::getItemSpawn() const {
      return tileManager->getItemSpawnPosition();
    }

    const Utils::VectorF Level::getBossSpawn() const {
      return tileManager->getBossSpawnPosition();
    }

    Managers::CollisionManager* Level::getCollisionManager() { 
      return &collisions;
    }

    Managers::EventManager* Level::getEventManager() const{ 
      return events;
    }
    
    Managers::GraphicsManager* Level::getGraphicsManager() const {
      return graphics;
    }

    void Level::markForDelete(Entities::PhysicalEntity* ent) {
      markedToDelete.insert(ent);
    }

    void Level::endLevel() {
      decision = 1;
      keep_going = false;
    }

    void Level::generateEnemies() {
      std::vector<Utils::VectorF> spawns = tileManager->getEnemySpawns();
      int nEnemies = Utils::RandomValueGenerator::getInstance()->getRandomIntInRange(5, 10);
      
      for (int i = 0; i < nEnemies; ++i) {
        
        int idx = Utils::RandomValueGenerator::getInstance()->getRandomIntInRange(0, spawns.size());
        Entities::Enemy* enemy = new Entities::Leaper();
        enemy->setLevel(this);
        enemy->initializeGeneric(this);
        Utils::VectorF pos = spawns[idx] + Utils::VectorF(32.0f, 32.0f) * .5 - enemy->getSize() * .5;

        enemy->setPosition(Utils::VectorF(pos.x, pos.y));
        entities.addEntity(enemy);
        collisions.addToCollisions(enemy);

        idx = Utils::RandomValueGenerator::getInstance()->getRandomIntInRange(0, spawns.size());
        enemy = new Entities::Caster();
        enemy->setLevel(this);
        enemy->initializeGeneric(this);
        pos = spawns[idx] + Utils::VectorF(32.0f, 32.0f) * .5 - enemy->getSize() * .5;
        
        enemy->setPosition(Utils::VectorF(pos.x, pos.y));

        entities.addEntity(enemy);
        collisions.addToCollisions(enemy);

      }
    }

    void Level::addPhysicalEntity(Entities::PhysicalEntity* ent) {
      ent->initializeGeneric(this);
      entities.addEntity(ent);
      collisions.addToCollisions(ent);
    }

    void Level::setPlayers(Entities::TheUndying* p1, Entities::ThePenitent* p2) {
      
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

      generateEnemies();

    }

    int Level::exec() {
      keep_going = true;
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
        graphics->display();
      }

      for (Entities::PhysicalEntity* ent : markedToDelete) {

        entities.removeWithoutDestroying(ent);
        collisions.removeFromCollisions(ent);
        delete ent;

      }
      markedToDelete.clear();
      return decision;
    }

    void Level::saveState() const {
      std::ofstream levelOut(saveFilePath);
      Mementos::LevelMemento memento(tileManager, player1, player2, &collisions);
      
      memento.saveToFile(levelOut);
    }
    
    void Level::loadLastSaved() {
      std::ifstream levelIn(saveFilePath);
      if (levelIn) {
        Mementos::LevelMemento memento = Mementos::LevelMemento::loadFromFile(levelIn);
        if (player1 == nullptr) {
          throw 'k';
        }
        tileManager->regenRandomTiles();
        entities.removeWithoutDestroying(tileManager);
        entities.removeWithoutDestroying(player1);
        entities.removeWithoutDestroying(player2);
        entities.destroyAll();
        collisions.removeAll();

        tileManager->loadMemento(memento.getTileManagerMemento());
        entities.addEntity(tileManager);

        player1->loadMemento(memento.getPlayer1Memento());
        entities.addEntity(player1);
        collisions.addToCollisions(player1);
        
        if (player2 != nullptr) {
          if (memento.savedPlayer2()) {
            player2->loadMemento(memento.getPlayer2Memento());
          }
          entities.addEntity(player2);
          collisions.addToCollisions(player2);
        }

        Entities::TheMirrorOfHastur* mirror = nullptr;
        Entities::TheChained* boss = nullptr;
        for (std::pair<std::string, Mementos::Memento*>& p : memento.getOtherEntitiesMemento()) {
          if (p.first == "Bullet") {
            Entities::Bullet* bullet = new Entities::Bullet;
            bullet->loadMemento(*static_cast<Mementos::BulletMemento*>(p.second));
            addPhysicalEntity(bullet);
          } else if (p.first == "Spell") {
            Entities::Spell* spell = new Entities::Spell;
            spell->loadMemento(*static_cast<Mementos::SpellMemento*>(p.second));
            addPhysicalEntity(spell);
          } else if (p.first == "Caster") {
            Entities::Caster* caster = new Entities::Caster;
            caster->loadMemento(*static_cast<Mementos::CasterMemento*>(p.second));
            addPhysicalEntity(caster);
          } else if (p.first == "Leaper") {
            Entities::Leaper* leaper = new Entities::Leaper;
            leaper->loadMemento(*static_cast<Mementos::LeaperMemento*>(p.second));
            addPhysicalEntity(leaper);
          } else if (p.first == "Mirror") {
            mirror = new Entities::TheMirrorOfHastur;
            mirror->loadMemento(*static_cast<Mementos::TheMirrorOfHasturMemento*>(p.second));
            addPhysicalEntity(mirror);
          } else if (p.first == "Boss") {
            boss = new Entities::TheChained(nullptr);
            boss->loadMemento(*static_cast<Mementos::TheChainedMemento*>(p.second));
            addPhysicalEntity(boss);
          }
        }
        if (mirror != nullptr && boss != nullptr) {
          boss->setMirror(mirror);
        }
      } else {
        playFromStart();
      }
    }
  
  }
}