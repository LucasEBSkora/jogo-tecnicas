#ifndef TEXTINPUTBOX_HPP
#define TEXTINPUTBOX_HPP

#include <string>

#include "../Utils/GeometricVector.hpp"

namespace DIM {

  namespace Managers {
   class EventManager;
   class GraphicsManager;
  }


  namespace Menus {
    class TextInputBox {
       private: 
        Managers::GraphicsManager* graph;
        Managers::EventManager* events;
        unsigned int keyboard_event_id;
        Utils::VectorF centerPosition;
        unsigned int fontSize;
        unsigned short maxLenght;
        bool done;
        std::string str;
      public:
        
        TextInputBox(const unsigned short maxlenght = 10, Utils::VectorF pos = Utils::VectorF(), unsigned int font = 16);
        ~TextInputBox();

        void initialize(Managers::GraphicsManager& g, Managers::EventManager& e);
        void setCenter(const Utils::VectorF pos);
        void setFontSize(const unsigned int s);
        void draw() const;
        void addScore(const unsigned int score, const std::string name);
        void removeListeners();
        void startStringCapture();
        bool captureDone() const;
        std::string getCapture();

    };
  }
}

#endif