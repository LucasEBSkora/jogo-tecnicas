#ifndef PHYSICALENTITYLIST_HPP
#define PHYSICALENTITYLIST_HPP

#include "Entities/PhysicalEntity.hpp"
#include <list>
#include <deque>

namespace DIM {
  
  class PhysicalEntityList {
    private:
      std::list<PhysicalEntity*> entities;
    public:
      PhysicalEntityList();
      ~PhysicalEntityList();
      void push(PhysicalEntity* ent);
      void erase(PhysicalEntity* ent);
      void clear();
      std::deque<PhysicalEntity*> asDeque() const;
      const std::list<PhysicalEntity*>& asStdList() const;
  };


} // namespace DIM


#endif