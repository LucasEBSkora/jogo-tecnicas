#include "TextInputBox.hpp"

#include "../Managers/EventManager.hpp"

#include <iostream>

namespace DIM {

  namespace Menus {
    TextInputBox::TextInputBox(const unsigned short maxlenght, Utils::VectorF pos, unsigned int font) 
    : graph{nullptr}, events{nullptr}, keyboard_event_id{0}, centerPosition{pos}, fontSize{font}, 
    maxLenght{maxlenght}, done{false}, str{""}  {

    }

    TextInputBox::~TextInputBox() {

    }


    void TextInputBox::initialize(Managers::GraphicsManager& g, Managers::EventManager& e) {
      graph = &g;
      events = &e;
    }

    void TextInputBox::setCenter(const Utils::VectorF pos) {
      centerPosition = pos;
    }

    void TextInputBox::setFontSize(const unsigned int s) {
      fontSize = s;
    }


    void TextInputBox::draw() const {
      graph->drawTextCentered(str, centerPosition, fontSize);
    }

    void TextInputBox::addScore(const unsigned int score, const std::string name) {

    }

    void TextInputBox::removeListeners() {
      if (keyboard_event_id != 0) {
        events->removeKeyboardListener(keyboard_event_id);
        keyboard_event_id = 0;
      }

    }
    
    void TextInputBox::startStringCapture() {
      keyboard_event_id = events->addKeyboardListener([this](Managers::EventManager::Event e) {
        if (e.getType() == Managers::EventManager::EventType::TextEntered) {
          if (str.size() <= 10) {
            char c = e.getChar();
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) 
              str += c;
            
          }
        } else if (e.getType() == Managers::EventManager::EventType::KeyReleased) {
          if (e.getKey() == Managers::EventManager::Key::Backspace) {
            if (str.size() > 0) str.pop_back();
          } else if (e.getKey() == Managers::EventManager::Key::Enter) {
            done = true;
            removeListeners();
          }
        }
      });
    }

    bool TextInputBox::captureDone() const {
      return done;
    }

    std::string TextInputBox::getCapture() {
      if (!done) throw "nope";
      done = false;
      std::string cpy{str};
      str = "";
      return cpy; 
    
    }



  }
}