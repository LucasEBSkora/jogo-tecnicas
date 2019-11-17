#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <set>
#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"
#include "../CollisionManager.hpp"
#include "../Entities/Entity.hpp"
#include "../Entities/Mob.hpp"
#include "../Lists/EntityList.hpp"
#include "../TileSystem/TileManager.hpp"

#include <set>

namespace DIM {
  class PhysicalEntity;

  class Level {

  protected:
    GraphicsManager* graphics;
    EventManager* events;
    CollisionManager collisions;
    EntityList entities;
    Mob* player1;
    Mob* player2;
    TileManager* tileManager;
    std::set<PhysicalEntity*> markedToDelete;
    int decision;
    bool keep_going;
    const std::string backgroundPath;

  public:
    Level(const std::string background = "");
    virtual ~Level();

    virtual void init(GraphicsManager& g, EventManager& e);

    virtual void bindPlayers(Mob* p1, Mob* p2 = nullptr);
    virtual void addPhysicalEntity(PhysicalEntity* ent);
    virtual void generateEnemies();

    
    virtual void setup();
    virtual int exec();

    const VectorF getPlayer1Center() const;
    const VectorF getPlayer1Spawn() const;
    CollisionManager* getCollisionManager();
    EventManager* getEventManager() const;
    GraphicsManager* getGraphicsManager() const;

    void markForDelete(PhysicalEntity* ent);
    void endLevel();

  };

}

#endif