#include "LeaderBoardMenu.hpp"

#include <fstream>
#include <iostream>

namespace DIM {

  namespace Menus {

    LeaderBoardMenu::LeaderBoardMenu() :  addingScore{false} {

    }

    LeaderBoardMenu::~LeaderBoardMenu(){

    }

    void LeaderBoardMenu::init(Managers::GraphicsManager& g, Managers::EventManager& e) { 
      Menu::init(g, e);

      Utility::VectorF viewsize = g.getViewSize();
      
      buttons.push_back(new Button(Utility::VectorF(viewsize.x * 6.5 / 8, viewsize.y * 0.5 / 10 ), 160, 30, 0, "Main Menu"));

      for (auto& b : buttons) {
        b->initialize(g, e);
      }

      box.setCenter(Utility::VectorF(viewsize.x * 3/8, viewsize.y * 0.5 / 10));
      box.initialize(g, e);
      
      leaderboard.initialize(g, e);
      leaderboard.setPosition(Utility::VectorF(viewsize.x/8, viewsize.y * 1.5/10));
      leaderboard.setSize(Utility::VectorF(viewsize.x* 6/8, viewsize.y* 9/10));
    }

    const int LeaderBoardMenu::exec() {

      Utility::VectorF viewsize = graphics->getViewSize();
      graphics->centerCamera(viewsize * .5);
      keep_going = true;
      return_val = 0;

      mouse_event_id = events->addMouseListener(
        [this] (Managers::EventManager::Event e) {
          if (e.getType() == Managers::EventManager::EventType::MouseButtonPressed) {
            Utility::VectorF pos = graphics->getMousePosInView();
            for (auto& b : buttons) {
              if (b->isInside(pos)) {
                if (b->getId() == 0) keep_going = false;
                
              }
            }
          }
        }
      );

      if (addingScore) box.startStringCapture();
      leaderboard.subscribe();

      while (keep_going) {
        events->processEvents();
        
        if (addingScore) {
          
          if (box.captureDone()) {
            std::string name = box.getCapture();
            if (name != "") {
              leaderboard.addScore(score, name);
            }
            addingScore = false;
            score = 0;
          }
        }

        graphics->clear(20, 20, 20);
        for (auto& b : buttons) b->draw();
        leaderboard.draw();
        box.draw();
        graphics->display();
      }

      leaderboard.removeListeners();
      box.removeListeners();

      removeListeners();
      
      score = 0;
      addingScore = false;

      return return_val;
    }


    void LeaderBoardMenu::addNewHighScore(const int deaths) {
      
      score = deaths;
      addingScore = true;

    }
    
  }
}