#include "LeaderBoard.hpp"

namespace DIM {

  namespace Menus {

    LeaderBoard::LeaderBoard(){
      
    }

    LeaderBoard::~LeaderBoard(){
      if (key_event_id != 0) {
        events->removeKeyboardListener(key_event_id);
        key_event_id = 0;
      }
      if (mouse_event_id != 0) {
        events->removeMouseListener(mouse_event_id);
        mouse_event_id = 0;
      }
    }

    void LeaderBoard::init(Managers::GraphicsManager& g, Managers::EventManager& e){
      Menu::init(g, e);

    }

    const int LeaderBoard::exec(){
      return 0;
    }


    void LeaderBoard::addNewHighScore(const int deaths) {

    }
  }
}