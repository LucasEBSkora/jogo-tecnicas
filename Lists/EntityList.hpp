#ifndef ENTITYLIST_HPP
#define ENTITYLIST_HPP

#include "List.hpp"
#include "../Entities/Entity.hpp"

namespace DIM {

  class EntityList {
  private:
    List<Entity*> entities;
  public:
    using iterator = List<Entity*>::iterator;

    EntityList();
    ~EntityList();

    void addEntity(Entity* ent);
    void removeWithoutDestroying(Entity* ent);

    void drawAll();
    void updateAll(float elapsedTime);
    void initializeAll(GraphicsManager& g, EventManager& e);
    void destroyAll();

    iterator begin();
    iterator end();
  };

}

#endif