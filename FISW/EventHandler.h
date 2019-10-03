#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "EventHandlerSettings.h"
#include "EventReport.h"
#include <SFML/Graphics.hpp>

namespace FISW {


  //classe que lerá os eventos provindos do sistema e os distribui através da classe EventReport pela estrutura. 
  //Tem que ser refeito para funcionar por notificação
  class EventHandler {
    
    private:
      FISW::EventHandlerSettings settings;
      FISW::EventReport report;
      sf::Clock clock;
    public:

    EventHandler(FISW::EventHandlerSettings Settings = FISW::EventHandlerSettings());
    ~EventHandler();

    void updateSettings(FISW::EventHandlerSettings Settings);
    const FISW::EventReport& processEvents(sf::RenderWindow* window);



  };

}

#endif