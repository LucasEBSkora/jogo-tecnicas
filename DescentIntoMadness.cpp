#include "DescentIntoMadness.hpp"
#include <iostream>

namespace DIM {

  DescentIntoMadness::DescentIntoMadness() :
    graphics_man(), events_man(), menu(), pause(), player1(), player2(), temple(), cavern(),
    current(GameState::MAIN_MENU), unpause{GameState::END_GAME} {
    
    events_man.setGraphicsManager(graphics_man);
    menu.init(graphics_man, events_man);
    temple.init(graphics_man, events_man);
    cavern.init(graphics_man, events_man);

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
    menu.init(graphics_man, events_man);
    int decisao = menu.exec();
    if (decisao == 0) {
      current = GameState::END_GAME;
    } else if (decisao == 1) {

      unpause = current = GameState::TEMPLE_LEVEL;
      
      goToLevel(&temple);

    } else if (decisao == 2) {
      // memento
      // current = GameState::TEMPLE_LEVEL;
    } else if (decisao == 3) {
      
      unpause = current = GameState::CAVERN_LEVEL;
      
      
      goToLevel(&cavern);

    
    } else if (decisao == 4) {
      // memento
      // current = GameState::CAVERN_LEVEL;
    }
  }

  void DescentIntoMadness::pauseMenu() {
    pause.init(graphics_man, events_man);
    int decisao = pause.exec();
    if (decisao == 0) {
      current = unpause;
    } else if (decisao == 1) {
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
      temple.unbindPlayers();
      goToLevel(&cavern);
    } 
  }

  void DescentIntoMadness::cavernLevel() {
    int dec = cavern.exec();
    if (dec == 0) current = GameState::PAUSE_MENU;
    else if (dec == 1) {
      unpause = current = GameState::END_GAME;
      cavern.unbindPlayers();
    } 
  }
  
  void DescentIntoMadness::goToLevel(Level* level) {
    player1.initializeGeneric(level);
    if (menu.useTwoPlayers()) player2.initializeGeneric(level);
    

    level->bindPlayers(&player1, menu.useTwoPlayers() ? &player2 : nullptr);
    level->setup();

  }
}