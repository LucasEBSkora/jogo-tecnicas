#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <set>
#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"
#include "../CollisionManager.hpp"
#include "../Entities/Entity.hpp"
#include "../Entities/Players/ThePenitent.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Lists/EntityList.hpp"
#include "../TileSystem/TileManager.hpp"
#include "../Mementos/LevelMemento.hpp"

namespace DIM {
  class PhysicalEntity;

  class Level {

  protected:
    GraphicsManager* graphics;
    EventManager* events;
    CollisionManager collisions;
    EntityList entities;
    TheUndying* player1;
    ThePenitent* player2;
    TileManager* tileManager;
    std::set<PhysicalEntity*> markedToDelete;
    int decision;
    bool keep_going;
    const std::string backgroundPath;

  public:
    Level(const std::string background = "");
    virtual ~Level();

    virtual void init(GraphicsManager& g, EventManager& e);

    virtual void setPlayers(TheUndying* p1, ThePenitent* p2 = nullptr);
    virtual void addPhysicalEntity(PhysicalEntity* ent);
    virtual void generateEnemies();

    
    virtual void playFromStart();
    virtual void loadMemento(LevelMemento memento) = 0;
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