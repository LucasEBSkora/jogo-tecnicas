#include "DescentIntoMadness.hpp"
#include <iostream>

namespace DIM {

  DescentIntoMadness::DescentIntoMadness() :
    // graphics_man(), menu(), temple(), cavern() {
    graphics_man(), menu(), temple(), current(GameState::MAIN_MENU) {
    events_man.setGraphicsManager(graphics_man);
    menu.init(graphics_man, events_man);
    temple.init(graphics_man, events_man);
    player1.initializeGeneric(&temple);
    player2.initializeGeneric(&temple);
    temple.bindPlayers(&player1, &player2);
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
    // menu.exec();
    // temple.exec();
    // while (playing) {
    //   // a partir daqui pseudocódigo por enquanto
    //   int decisao = menu.exec();
    //   if (decisao == FIM) {
    //     playing = false;
    //   } else if (decisao == NOVO_TEMPLE) {
    //     temple.newgame();
    //     decisao = temple.exec();
    //     if (decisao == PROX_FASE) {
    //       cavern.newgame();
    //       cavern.exec();
    //     }
    //   }
    // 
    
  }

  void DescentIntoMadness::mainMenu() {
    menu.init(graphics_man, events_man);
    int decisao = menu.exec();
    if (decisao == 0) {
      current = GameState::END_GAME;
    } else if (decisao == 1) {
      current = GameState::TEMPLE_LEVEL;
      temple.setup();
    } else if (decisao == 2) {
      // memento
      // current = GameState::TEMPLE_LEVEL;
    } else if (decisao == 3) {
      // current = GameState::CAVERN_LEVEL;
    } else if (decisao == 4) {
      // memento
      // current = GameState::CAVERN_LEVEL;
    }
  }

  void DescentIntoMadness::pauseMenu() {
    current = GameState::END_GAME;
  }

  void DescentIntoMadness::templeLevel() {
    temple.exec();
    current = GameState::MAIN_MENU;
  }

  void DescentIntoMadness::cavernLevel() {
    current = GameState::END_GAME;
  }

}