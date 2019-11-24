#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <set>
#include "../Managers/GraphicsManager.hpp"
#include "../Managers/EventManager.hpp"
#include "../Managers/CollisionManager.hpp"
#include "../Entities/Entity.hpp"
#include "../Entities/Players/ThePenitent.hpp"
#include "../Entities/Players/TheUndying.hpp"
#include "../Lists/EntityList.hpp"
#include "../Tiles/TileManager.hpp"
#include "../Mementos/LevelMemento.hpp"

namespace DIM {


  namespace Entities {
    class PhysicalEntity;
  }

  namespace Levels {

    class Level {
    protected:
      Managers::GraphicsManager* graphics;
      Managers::EventManager* events;
      Managers::CollisionManager collisions;
      Lists::EntityList entities;
      Entities::Mobs::TheUndying* player1;
      Entities::Mobs::ThePenitent* player2;
      Tiles::TileManager* tileManager;
      std::set<Entities::PhysicalEntity*> markedToDelete;
      int decision;
      bool keep_going;
      const std::string backgroundPath;
      std::string saveFilePath;

    public:
      Level(const std::string background = "");
      virtual ~Level();

      virtual void init(Managers::GraphicsManager& g, Managers::EventManager& e);

      virtual void setPlayers(Entities::Mobs::TheUndying* p1, Entities::Mobs::ThePenitent* p2);
      virtual void setPlayers(Entities::Mobs::TheUndying* p1);
      virtual void addPhysicalEntity(Entities::PhysicalEntity* ent);
      virtual void generateEnemies();

      
      virtual void playFromStart();
      virtual int exec();

      const Utils::VectorF getPlayer1Center() const;
      const Utils::VectorF getPlayer1Spawn() const;
      const Utils::VectorF getItemSpawn() const;
      const Utils::VectorF getBossSpawn() const;
      Managers::CollisionManager* getCollisionManager();
      Managers::EventManager* getEventManager() const;
      Managers::GraphicsManager* getGraphicsManager() const;

      void markForDelete(Entities::PhysicalEntity* ent);
      void endLevel();

      void saveState() const;
      void loadLastSaved();
    };

  }
}

#endif