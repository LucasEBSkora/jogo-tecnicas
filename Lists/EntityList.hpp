#ifndef ENTITYLIST_HPP
#define ENTITYLIST_HPP

#include "List.hpp"
#include "../Entities/Entity.hpp"

namespace DIM {

  class EntityList {
  private:
    using entity_iterator = List<Entity*>::iterator;
    List<Entity*> entities;
  public:
    EntityList();
    ~EntityList();

    void addEntity(Entity* ent);

    void drawAll();
    void updateAll(float elapsedTime);
    void inicializeAll(GraphicsManager* g);
    void destroyAll();
  };

}

#endif