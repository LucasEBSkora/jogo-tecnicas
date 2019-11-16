#ifndef DESCENTINTOMADNESS_HPP
#define DESCENTINTOMADNESS_HPP

#include "GraphicsManager.hpp"
#include "EventManager.hpp"
#include "Menus/MainMenu.hpp"
#include "Menus/PauseMenu.hpp"
#include "Levels/TempleLevel.hpp"
#include "Levels/CavernLevel.hpp"
#include "Entities/Players/TheUndying.hpp"
#include "Entities/Players/ThePenitent.hpp"

namespace DIM {
  
  class DescentIntoMadness {
  private:

    enum class GameState {
      MAIN_MENU,
      PAUSE_MENU,
      TEMPLE_LEVEL,
      CAVERN_LEVEL,
      END_GAME,
    };

    GraphicsManager graphics_man;
    EventManager events_man;

    MainMenu menu;
    PauseMenu pause;

    TempleLevel temple;
    // CavernLevel cavern;
    
    TheUndying player1;
    ThePenitent player2;

    GameState current;

    void play();

    void mainMenu();
    void pauseMenu();
    void templeLevel();
    void cavernLevel();
  public:
    DescentIntoMadness();
    ~DescentIntoMadness();
  };
  
}

#endif