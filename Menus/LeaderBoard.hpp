#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include "Menu.hpp"

namespace DIM {

  namespace Menus {
    
    class LeaderBoard : public Menu {
      
      private:


      public:

        LeaderBoard();
        ~LeaderBoard();

        void init(Managers::GraphicsManager& g, Managers::EventManager& e) override;

        void addNewHighScore(const int deaths);
        const int exec() override;

      
    };
  }
  
} 



#endif