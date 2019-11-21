#ifndef PHYSICALENTITYLIST_HPP
#define PHYSICALENTITYLIST_HPP

#include "Entities/PhysicalEntity.hpp"
#include <list>
#include <deque>

namespace DIM {
  
  class PhysicalEntityList {
    private:
      std::list<Entities::PhysicalEntity*> entities;
    public:
      PhysicalEntityList();
      ~PhysicalEntityList();
      void push(Entities::PhysicalEntity* ent);
      void erase(Entities::PhysicalEntity* ent);
      void clear();
      std::deque<Entities::PhysicalEntity*> asDeque() const;
      const std::list<Entities::PhysicalEntity*>& asStdList() const;
  };

}


#endif