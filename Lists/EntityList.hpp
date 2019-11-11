#ifndef ENTITYLIST_HPP
#define ENTITYLIST_HPP

#include "List.hpp"
#include "../Entities/Entity.hpp"

namespace DIM {

  class EntityList : public List<Entity*> { // a EntityList compõe uma List<Entity*>, não herda
    public:
      EntityList();
      ~EntityList();
      void DrawAll();
      void UpdateAll();
      void InicializeAll();
      void DestroyAll();

  };
}

#endif