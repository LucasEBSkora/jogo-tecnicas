#include "DescentIntoMadness.hpp"
#include <iostream>
#include <fstream>

namespace DIM {

  DescentIntoMadness::DescentIntoMadness() :
    graphics_man(), events_man(), menu(), pause(), player1(), player2(), temple(), cavern(),
    current(GameState::MAIN_MENU), unpause{GameState::END_GAME} {
    
    events_man.setGraphicsManager(graphics_man);
    menu.init(graphics_man, events_man);
    pause.init(graphics_man, events_man);
    temple.init(graphics_man, events_man);
    cavern.init(graphics_man, events_man);

    player1.initializeGeneric(&temple); // só para usar o graphics manager e eventos
    player2.initializeGeneric(&temple);
    player1.setLevel(nullptr);
    player2.setLevel(nullptr);

    play();
  }

  DescentIntoMadness::~DescentIntoMadness() {

  }

  void DescentIntoMadness::play() {
    bool playing = true;
    while (playing) {
      switch (current) {
        case GameState::MAIN_MENU:
          mainMenu();
          break;
        case GameState::PAUSE_MENU:
          pauseMenu();
          break;
        case GameState::TEMPLE_LEVEL:
          templeLevel();
          break;
        case GameState::CAVERN_LEVEL:
          cavernLevel();
          break;
        case GameState::END_GAME:
        default:
          playing = false;
          break;
      }
    }
    
  }

  void DescentIntoMadness::mainMenu() {
    int decisao = menu.exec();
    if (decisao == 0) {
      current = GameState::END_GAME;
    } else if (decisao == 1) {

      unpause = current = GameState::TEMPLE_LEVEL;
      goToLevel(&temple);
      temple.playFromStart();

    } else if (decisao == 2) {
      std::ifstream templeIn("templeSave.txt");
      if (templeIn) {
        unpause = current = GameState::TEMPLE_LEVEL;
        goToLevel(&temple);
        temple.loadMemento(LevelMemento::loadFromFile(templeIn));
      }
    } else if (decisao == 3) {
      
      unpause = current = GameState::CAVERN_LEVEL;
      goToLevel(&cavern);
      cavern.playFromStart();
    
    } else if (decisao == 4) {
      std::ifstream cavernIn("cavernSave.txt");
      if (cavernIn) {
        unpause = current = GameState::CAVERN_LEVEL;
        goToLevel(&cavern);
        cavern.loadMemento(LevelMemento::loadFromFile(cavernIn));
      }
    }
  }

  void DescentIntoMadness::pauseMenu() {
    int decisao = pause.exec();
    if (decisao == 0) {
      current = unpause;
    } else if (decisao == 1) {
      if (unpause == GameState::TEMPLE_LEVEL) {
        std::ofstream templeOut("templeSave.txt");
        temple.createMemento().saveToFile(templeOut);
      } else {
        std::ofstream cavernOut("cavernSave.txt");
        cavern.createMemento().saveToFile(cavernOut);
      }
      current = unpause;
    } else if (decisao == 2) {
      current = GameState::MAIN_MENU;
    }
  }

  void DescentIntoMadness::templeLevel() {
    int dec = temple.exec();
    if (dec == 0) current = GameState::PAUSE_MENU;
    else if (dec == 1) {
      unpause = current = GameState::CAVERN_LEVEL;
      goToLevel(&cavern);
    }
  }

  void DescentIntoMadness::cavernLevel() {
    int dec = cavern.exec();
    if (dec == 0) current = GameState::PAUSE_MENU;
    else if (dec == 1) {
      unpause = current = GameState::END_GAME;
    } 
  }
  
  void DescentIntoMadness::goToLevel(Level* level) {
    player1.setLevel(level);
    player2.setLevel(menu.useTwoPlayers() ? level : nullptr);

    level->setPlayers(&player1, menu.useTwoPlayers() ? &player2 : nullptr);

  }
}