#ifndef EVENTHANDLERSETTINGS_H
#define EVENTHANDLERSETTINGS_H

#include <functional>
#include <vector>

#include <SFML/Graphics.hpp>

#include "constants.h"

namespace FISW {

// needs to be redone in a more event oriented way
// being redone
// enum EventTypes {
//     UpdateEvent,
//     DrawEvent,
//     KeyboardEvent,
//     MouseEvent,
// };

class EventHandlerSettings {

private:
    std::vector<std::function<void(float)>> updates;
    std::vector<std::function<void(sf::RenderWindow*)>> draws;

public:
    EventHandlerSettings();

    ~EventHandlerSettings();

    // join the sets that compose the settings
    void join(const EventHandlerSettings& settings);

    // adds functions to the vectors
    void addUpdate(std::function<void(float)> f);
    void addDraw(std::function<void(sf::RenderWindow*)> f);

    friend class EventHandler;
};

} // namespace FISW

#endif