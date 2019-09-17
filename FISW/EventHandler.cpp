#include "EventHandler.h"

#include <iostream>
#include <string>

namespace FISW {

  EventHandler::EventHandler(EventHandlerSettings Settings) 
    : settings{Settings} {

  }

  EventHandler::~EventHandler() {

  }

  void EventHandler::updateSettings(EventHandlerSettings Settings) {
    settings = Settings;
  }

  const EventReport& EventHandler::processEvents(sf::RenderWindow* window) {

    report.passedTime = clock.restart().asSeconds();

    sf::Event evnt;

    while (window->pollEvent(evnt)) {
      
      if (evnt.type == sf::Event::Closed) {

        std::cout << "close button pressed!" << std::endl;
        report.closeGame = true;
        
      }
      else if (evnt.type == sf::Event::TextEntered) {
        if (evnt.text.unicode < 128)

          std::cout << static_cast<char>(evnt.text.unicode) << std::flush;
          
      }
    }

    return report;

  }

}