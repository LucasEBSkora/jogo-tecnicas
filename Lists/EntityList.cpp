#include "EntityList.hpp"

namespace DIM {
  EntityList::EntityList() { 

  }

  EntityList::~EntityList(){ 
    destroyAll();
  }

  void EntityList::addEntity(Entity* ent){
    entities.AddElementBack(ent);
  }

  void EntityList::drawAll(){ 
    for (entity_iterator i = entities.begin(); i != entities.end(); ++i) {
      (*i)->draw();
    }
  }

  void EntityList::updateAll(float elapsedTime){ 
    for (entity_iterator i = entities.begin(); i != entities.end(); ++i) {
      (*i)->update(elapsedTime);
    }
  }

  void EntityList::inicializeAll(GraphicsManager* g){
    for (entity_iterator i = entities.begin(); i != entities.end(); ++i) {
      (*i)->initializeGeneric(g);
    }
  }

  void EntityList::destroyAll(){
    for (entity_iterator i = entities.begin(); i != entities.end(); ++i) {
      delete (*i);
    }
  }

}