#ifndef ENTITYLIST_HPP
#define ENTITYLIST_HPP

#include "List.hpp"
#include "../Entities/Entity.hpp"

namespace DIM {
  namespace Lists {

    class EntityList {
    private:
      List<Entities::Entity*> entities;
    public:
      using iterator = List<Entities::Entity*>::iterator;

      EntityList();
      ~EntityList();

      void addEntity(Entities::Entity* ent);
      void removeWithoutDestroying(Entities::Entity* ent);

      void drawAll();
      void updateAll(float elapsedTime);
      void initializeAll(Levels::Level* level);
      void destroyAll();

      iterator begin();
      iterator end();
    };

  }
}

#endif