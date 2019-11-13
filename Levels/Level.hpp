#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"
#include "../Entities/Entity.hpp"
#include "../Entities/Mob.hpp"
#include "../Lists/EntityList.hpp"
#include "../TileSystem/TileManager.hpp"

namespace DIM {
  class Level {

  protected:
    GraphicsManager* graphics;
    EventManager* events;
    EntityList entities;
    Mob* player1;
    Mob* player2;
    TileManager* tileManager;

  public:
    Level(Mob* p1 = nullptr, Mob* p2 = nullptr);
    virtual ~Level();

    virtual void init(GraphicsManager& g, EventManager& e);

    virtual void exec() = 0;
  };

}

#endif