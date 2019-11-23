#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include <map>
#include <string>

#include "../GeometricVector.hpp"




namespace DIM {

  namespace Managers {
   class EventManager;
   class GraphicsManager;
  }
    

  namespace Menus {
    class LeaderBoard {
      
      private: 
        std::multimap<unsigned int, std::string> scores;
        Managers::GraphicsManager* graph;
        Managers::EventManager* events;
        unsigned int mouse_event_id;
        const char* path;
        Utility::VectorF position;
        Utility::VectorF size;
        unsigned int fontSize;
        int offset;
      public:
        
        LeaderBoard(Utility::VectorF pos = Utility::VectorF(), Utility::VectorF Size = Utility::VectorF(), unsigned int font = 16);
        ~LeaderBoard();

        void initialize(Managers::GraphicsManager& g, Managers::EventManager& e);
        void subscribe();
        void setPosition(const Utility::VectorF pos);
        void setSize(const Utility::VectorF s);
        void setFontSize(const unsigned int s);
        void loadScores();
        void draw() const;
        void addScore(const unsigned int score, const std::string name);
        void removeListeners();

    };
  }
} // namespace DIM


#endif