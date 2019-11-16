#include "Level.hpp"
#include <iostream>


namespace DIM {

  Level::Level() : graphics(nullptr), events(nullptr), player1(nullptr),
    player2(nullptr), tileManager(nullptr) {
    
  }

  Level::~Level() {

  }

  void Level::init(GraphicsManager& g, EventManager& e) {
    graphics = &g;
    events = &e;
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
}