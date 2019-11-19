#include "LevelMemento.hpp"
#include <iostream>

#include "../TileSystem/TileManager.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Entities/Players/ThePenitent.hpp"
#include "../CollisionManager.hpp"

#include "../Entities/Enemies/Leaper.hpp"
#include "../Entities/Enemies/Caster.hpp"

#include "../Entities/Enemies/TheChained.hpp"
// #include "../Entities/TheMirrorOfHastur.hpp"
#include "../Entities/Projectiles/Bullet.hpp"
#include "../Entities/Projectiles/Spell.hpp"

namespace DIM {
  
  LevelMemento::LevelMemento() :
    tileManagerMemento(nullptr), player1Memento(nullptr), player2Memento(nullptr) {
    
  }

  LevelMemento::LevelMemento(TileManager* const tileManager, TheUndying* const p1, ThePenitent* const p2, const CollisionManager* collisionManager) :
    tileManagerMemento(nullptr), player1Memento(nullptr), player2Memento(nullptr) {
    tileManagerMemento = new TileManagerMemento(tileManager->createMemento());
    player1Memento = new TheUndyingMemento(p1->createMemento());
    if (p2 != nullptr) player2Memento = new ThePenitentMemento(p2->createMemento());
    for (PhysicalEntity* e : collisionManager->getCollidables()) {
      if (e == p1 || e == p2) continue;
      if (e->getID() == "Bullet") {
        otherMementos.emplace_back("Bullet", new BulletMemento(static_cast<Bullet*>(e)->createMemento()));
      } else if (e->getID() == "Spell") {
        otherMementos.emplace_back("Spell", new SpellMemento(static_cast<Spell*>(e)->createMemento()));
      } else if (e->getID() == "Caster") {
        otherMementos.emplace_back("Caster", new CasterMemento(static_cast<Caster*>(e)->createMemento()));
      } else if (e->getID() == "Leaper") {
        otherMementos.emplace_back("Leaper", new LeaperMemento(static_cast<Leaper*>(e)->createMemento()));
      }

      // } else if (e->getID() == "TheMirrorOfHastur") {
        
      // }

    }
  }

  // LevelMemento::LevelMemento(const LevelMemento& other) :
  //   tileManagerMemento(other.getTileManagerMemento()), 
  //   player1Memento(other.getPlayer1Memento()),
  //   player2Memento(other.getPlayer2Memento()) {
  //   std::cout << "copiando memento" << std::endl;
  //   for (unsigned i = 0; i < other.otherMementos.size(); ++i) {
  //     if (other.otherMementos[i].first == "Bullet") {
  //       otherMementos.emplace_back("Bullet", new BulletMemento(*static_cast<BulletMemento*>(other.otherMementos[i].second)));
  //     } else if (other.otherMementos[i].first == "Spell") {
  //       otherMementos.emplace_back("Spell", new SpellMemento(*static_cast<SpellMemento*>(other.otherMementos[i].second)));
  //     } else if (other.otherMementos[i].first == "Caster") {
  //       otherMementos.emplace_back("Caster", new CasterMemento(*static_cast<CasterMemento*>(other.otherMementos[i].second)));
  //     } else if (other.otherMementos[i].first == "Leaper") {
  //       otherMementos.emplace_back("Leaper", new LeaperMemento(*static_cast<LeaperMemento*>(other.otherMementos[i].second)));
  //     }
  //   }
  // }
  
  LevelMemento::~LevelMemento() {
    delete tileManagerMemento;
    delete player1Memento;
    if (player2Memento != nullptr) delete player2Memento;
    for (unsigned i = 0; i < otherMementos.size(); ++i) {
      // std::cout << "destroying " << otherMementos[i].second << std::endl;
      delete otherMementos[i].second;
    }
  }

  TileManagerMemento LevelMemento::getTileManagerMemento() const {
    return *tileManagerMemento;
  }

  TheUndyingMemento LevelMemento::getPlayer1Memento() const {
    return *player1Memento;
  }

  ThePenitentMemento LevelMemento::getPlayer2Memento() const {
    return *player2Memento;
  }

  std::vector<std::pair<std::string, Memento*>> LevelMemento::getOtherEntitiesMemento() const {
    return otherMementos;
  }

  bool LevelMemento::savedPlayer2() const {
    return player2Memento != nullptr;
  }

  void LevelMemento::saveToFile(std::ostream& file) {
    tileManagerMemento->saveToFile(file);
    player1Memento->saveToFile(file);
    if (player2Memento != nullptr) {
      file << "1 ";
      player2Memento->saveToFile(file);
    } else {
      file << "0\n";
    }
    file << otherMementos.size() << ' ';
    for (auto& p : otherMementos) {
      file << p.first << ' ';
      p.second->saveToFile(file);
    }
  }

  LevelMemento LevelMemento::loadFromFile(std::istream& file) {
    LevelMemento memento;
    memento.tileManagerMemento = new TileManagerMemento(TileManagerMemento::loadFromFile(file));
    memento.player1Memento = new TheUndyingMemento(TheUndyingMemento::loadFromFile(file));
    bool p2 = false;
    file >> p2;
    if (p2) {
      memento.player2Memento = new ThePenitentMemento(ThePenitentMemento::loadFromFile(file));
    }
    
    unsigned mementosSize;
    file >> mementosSize;
    for (unsigned i = 0; i < mementosSize; ++i) {
      std::string id;
      file >> id;
      if (id == "Bullet") {
        memento.otherMementos.emplace_back("Bullet", new BulletMemento(BulletMemento::loadFromFile(file)));
      } else if (id == "Spell") {
        memento.otherMementos.emplace_back("Spell", new SpellMemento(SpellMemento::loadFromFile(file)));
      } else if (id == "Caster") {
        memento.otherMementos.emplace_back("Caster", new CasterMemento(CasterMemento::loadFromFile(file)));
      } else if (id == "Leaper") {
        memento.otherMementos.emplace_back("Leaper", new LeaperMemento(LeaperMemento::loadFromFile(file)));
      }
      // std::cout << "created " << memento.otherMementos[memento.otherMementos.size() - 1].second << std::endl;
      // } else if (id == "TheMirrorOfHastur") {
      // }
    }
    return memento;
  }
}