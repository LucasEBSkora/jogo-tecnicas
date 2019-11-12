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

    void drawAll();
    void updateAll(float elapsedTime);
    void inicializeAll(GraphicsManager* g);
    void destroyAll();

    iterator begin();
    iterator end();
  };

}

#endif