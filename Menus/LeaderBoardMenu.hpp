#ifndef LEADERBOARDMENU_HPP
#define LEADERBOARDMENU_HPP

#include "Menu.hpp"

#include <map>

#include "LeaderBoard.hpp"
#include "TextInputBox.hpp"

namespace DIM {

  namespace Menus {
    
    class LeaderBoardMenu : public Menu {
      
      private:
        
        LeaderBoard leaderboard;
        TextInputBox box;
        const char* path;
        bool addingScore;
        unsigned int score;


      public:

        LeaderBoardMenu();
        ~LeaderBoardMenu();

        void init(Managers::GraphicsManager& g, Managers::EventManager& e) override;

        void addNewHighScore(const int deaths);
        const int exec() override;

      
    };
  }
  
} 



#endif