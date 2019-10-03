#ifndef EVENTHANDLERSETTINGS_H
#define EVENTHANDLERSETTINGS_H

#include <set>

#include <SFML/Graphics.hpp>

#include "constants.h"

namespace FISW {

  //needs to be redone in a more event oriented way

  class EventHandlerSettings {
  
  private:
    
    std::set<KeyboardKey> registeredKeyboardKeys;
    std::set<MouseButton> registeredMouseButtons;
    std::set<MouseWheel> registeredMouseWheels;

  public:
    EventHandlerSettings(   
      std::set<KeyboardKey> keyboardKeys = std::set<KeyboardKey>(), 
      std::set<MouseButton> mouseButtons = std::set<MouseButton>(), 
      std::set<MouseWheel> mouseWheels = std::set<MouseWheel>()
    );
    
    ~EventHandlerSettings();
    
    //join the sets that compose the settings
    void join(const EventHandlerSettings& settings);
  
    friend class EventHandler;
  };
  
  
} 

#endif