#include "EventHandlerSettings.h"

namespace FISW {

EventHandlerSettings::EventHandlerSettings() {
}

EventHandlerSettings::~EventHandlerSettings() {
}

void EventHandlerSettings::join(const EventHandlerSettings& settings) {

    // joins the sets
    updates.insert(updates.end(), settings.updates.begin(), settings.updates.end());
    draws.insert(draws.end(), settings.draws.begin(), settings.draws.end());
}

void EventHandlerSettings::addUpdate(std::function<void(float)> f) {
    updates.push_back(f);
}

void EventHandlerSettings::addDraw(std::function<void(sf::RenderWindow*)> f) {
    draws.push_back(f);
}
} // namespace FISW
