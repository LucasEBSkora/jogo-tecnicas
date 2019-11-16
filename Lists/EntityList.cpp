#include "EntityList.hpp"

#include <iostream>

namespace DIM {
  EntityList::EntityList() { 

  }

  EntityList::~EntityList(){ 
    destroyAll();
  }

  void EntityList::addEntity(Entity* ent){
    
    entities.addElementBack(ent);
    std::cout << "tamanho" << entities.getSize() << std::endl; 
    
  }

  void EntityList::removeWithoutDestroying(Entity* ent){
    entities.removeFirstMatchingElement(ent);
    std::cout << "tamanho" << entities.getSize() << std::endl; 
  }

  void EntityList::drawAll(){ 
    
    for (iterator i = entities.begin(); i != entities.end(); ++i) {
      
      (*i)->draw();
    }
  }

  void EntityList::updateAll(float elapsedTime){ 
    for (iterator i = entities.begin(); i != entities.end(); ++i) {
      (*i)->update(elapsedTime);
    }
  }

  void EntityList::initializeAll(Level* level){
    for (iterator i = entities.begin(); i != entities.end(); ++i) {
      (*i)->initializeGeneric(level);
    }
  }

  void EntityList::destroyAll(){
    for (iterator i = entities.begin(); i != entities.end(); ++i) {
      delete (*i);
    }
  }

  EntityList::iterator EntityList::begin() {
    return entities.begin();
  }

  EntityList::iterator EntityList::end() {
    return entities.end();
  }

}