#include "EventHandler.h"

#include <iostream>

FISW::EventHandler::EventHandler(FISW::EventHandlerSettings Settings) 
  : settings{Settings} {

}

FISW::EventHandler::~EventHandler() {

}

void FISW::EventHandler::updateSettings(FISW::EventHandlerSettings Settings) {
  settings = Settings;
}

const FISW::EventReport& FISW::EventHandler::processEvents(sf::RenderWindow* window) {

	sf::Clock clock;

	float deltaTime = 0.0f;
  deltaTime = clock.restart().asSeconds();

  sf::Event evnt;

  while (window->pollEvent(evnt)) {
    
    if (evnt.type == sf::Event::Closed) {

      std::cout << "close button pressed!" << std::endl;
      report.closeGame = true;
      
    }
    else if (evnt.type == sf::Event::TextEntered) {
      if (evnt.text.unicode < 128)
        printf("%c", evnt.text.unicode);
        
    }
  }

  return report;

}
