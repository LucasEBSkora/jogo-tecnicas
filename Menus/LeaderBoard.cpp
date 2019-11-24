#include "LeaderBoard.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "../Managers/EventManager.hpp"
#include "../Managers/GraphicsManager.hpp"

namespace DIM {
  namespace Menus {

    LeaderBoard::LeaderBoard(Utils::VectorF pos, Utils::VectorF Size, unsigned int font) : mouse_event_id{0}, path{"high.score"}, 
    position{pos}, size{Size}, fontSize{font}, offset{0} {
      loadScores();
    }

    LeaderBoard::~LeaderBoard() {

    }


    void LeaderBoard::loadScores() {
      std::ifstream file;
      file.open(path);

      if (!file.is_open()) std::cout << "no high scores found!" << std::endl;
      else {
          unsigned int score;
          std::string name;
        while(file >> score >> name) {
          scores.emplace(score, name);
        }
      }
      file.close();
    }

    void LeaderBoard::addScore(const unsigned int score, const std::string name) {
      scores.emplace(score, name);
      std::ofstream file;
      file.open(path, std::fstream::in | std::fstream::ate);
      file << score << ' ' << name << std::endl;
      file.close();
    }

    void LeaderBoard::draw() const {
      Utils::VectorF positionText = position + Utils::VectorF(size.x/2, 0);      
      unsigned int skip = offset;
      for( auto p : scores) {
          if (skip > 0) {
            --skip;
            continue;
          }
          std::stringstream str;
          str << p.first << " - " << p.second << std::endl;
          graph->drawTextCentered(str.str(), positionText, fontSize);
          positionText += Utils::VectorF(0, fontSize);
          if (positionText.y >= size.y) break;
      }
    }

    void LeaderBoard::initialize(Managers::GraphicsManager& g, Managers::EventManager& e) {
      graph = &g;
      events = &e;

    }

    void LeaderBoard::subscribe() {
      mouse_event_id = events->addMouseListener([this] (Managers::EventManager::Event e) {
        if (e.getType() == Managers::EventManager::EventType::MouseWheelScrolledUp) --offset;
        else if (e.getType() == Managers::EventManager::EventType::MouseWheelScrolledDown) ++offset;
        if (offset < 0) offset = 0;
        else if (offset > static_cast<int> (scores.size()) - 1) offset = static_cast<int> (scores.size()) -1;
      });
    }

    void LeaderBoard::setPosition(const Utils::VectorF pos) {
      position = pos;
    }

    void LeaderBoard::setSize(const Utils::VectorF s) {
      size = s;
    }

    void LeaderBoard::setFontSize(const unsigned int s) {
      fontSize = s;
    }



    void LeaderBoard::removeListeners() {
      if (mouse_event_id != 0) {
        events->removeMouseListener(mouse_event_id);
        mouse_event_id = 0;
      }
    }
  }
}