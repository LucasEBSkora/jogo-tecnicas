#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "EventHandlerSettings.h"
#include "EventReport.h"
#include <SFML/Graphics.hpp>

namespace FISW {

// needs to be redone in a more event oriented way

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

} // namespace FISW

#endif