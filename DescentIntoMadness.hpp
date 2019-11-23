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
#include "Concurrent/ExtraLevel.hpp"

namespace DIM {
  
  class DescentIntoMadness {
  private:

    enum class GameState {
      MAIN_MENU,
      PAUSE_MENU,
      TEMPLE_LEVEL,
      CAVERN_LEVEL,
      EXTRA_LEVEL,
      END_GAME,
    };

    Managers::GraphicsManager graphics_man;
    Managers::EventManager events_man;

    Menus::MainMenu menu;
    Menus::PauseMenu pause;

    Entities::TheUndying player1;
    Entities::ThePenitent player2;

    Levels::TempleLevel temple;
    Levels::CavernLevel cavern;
    Concurrent::ExtraLevel extra;
    
    GameState current;
    GameState unpause;


    void play();

    void goToLevel(Levels::Level* level);

    void mainMenu();
    void pauseMenu();
    void templeLevel();
    void cavernLevel();
    void extraLevel();
  public:
    DescentIntoMadness();
    ~DescentIntoMadness();
  };
  
}

#endif