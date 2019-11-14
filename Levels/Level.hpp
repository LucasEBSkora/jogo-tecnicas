#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"
#include "../CollisionManager.hpp"
#include "../Entities/Entity.hpp"
#include "../Entities/Mob.hpp"
#include "../Lists/EntityList.hpp"
#include "../TileSystem/TileManager.hpp"

namespace DIM {
  class Level {

  protected:
    GraphicsManager* graphics;
    EventManager* events;
    CollisionManager collisions;
    EntityList entities;
    Mob* player1;
    Mob* player2;
    TileManager* tileManager;

  public:
    Level();
    virtual ~Level();

    virtual void init(GraphicsManager& g, EventManager& e);

    virtual void bindPlayers(Mob* p1, Mob* p2) = 0;

    virtual void exec() = 0;

    VectorF getPlayer1Center() const;
  };

}

#endif