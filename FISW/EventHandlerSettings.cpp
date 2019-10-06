#include "EventHandlerSettings.h"

namespace FISW {

EventHandlerSettings::EventHandlerSettings(std::set<FISW::KeyboardKey> keyboardKeys,
    std::set<FISW::MouseButton> mouseButtons, std::set<FISW::MouseWheel> mouseWheels)
    : registeredKeyboardKeys { keyboardKeys }
    , registeredMouseButtons { mouseButtons }
    , registeredMouseWheels { mouseWheels } {
}

EventHandlerSettings::~EventHandlerSettings() {
}

void EventHandlerSettings::join(const EventHandlerSettings& settings) {

    // joins the sets
    registeredKeyboardKeys.insert(settings.registeredKeyboardKeys.begin(), settings.registeredKeyboardKeys.end());
    registeredMouseButtons.insert(settings.registeredMouseButtons.begin(), settings.registeredMouseButtons.end());
    registeredMouseWheels.insert(settings.registeredMouseWheels.begin(), settings.registeredMouseWheels.end());
}
} // namespace FISW
