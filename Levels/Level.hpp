#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../EventManager.hpp"
#include "../Entities/Entity.hpp"
#include "../Entities/Mob.hpp"
#include "../Lists/EntityList.hpp"

namespace DIM {
  class Level {
  protected:
    GraphicsManager* graphics;
    EventManager events;
    EntityList entities;
    Mob* main_player;
  public:
    Level();
    virtual ~Level();

    virtual void init(GraphicsManager* g);

    virtual void exec() = 0;
  };

}

#endif