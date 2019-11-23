#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <set>
#include "../GraphicsManager.hpp"
#include "../EventManager.hpp"
#include "../CollisionManager.hpp"
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
      Entities::TheUndying* player1;
      Entities::ThePenitent* player2;
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

      virtual void setPlayers(Entities::TheUndying* p1, Entities::ThePenitent* p2 = nullptr);
      virtual void addPhysicalEntity(Entities::PhysicalEntity* ent);
      virtual void generateEnemies();

      
      virtual void playFromStart();
      virtual int exec();

      const Utility::VectorF getPlayer1Center() const;
      const Utility::VectorF getPlayer1Spawn() const;
      const Utility::VectorF getItemSpawn() const;
      const Utility::VectorF getBossSpawn() const;
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