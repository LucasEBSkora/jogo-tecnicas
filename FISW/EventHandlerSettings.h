#ifndef EVENTHANDLERSETTINGS_H
#define EVENTHANDLERSETTINGS_H

#include <set>

#include <SFML/Graphics.hpp>

#include "constants.h"

namespace FISW {


  class EventHandlerSettings {
  
  private:
    std::set<FISW::KeyboardKey> registeredKeyboardKeys;
    std::set<FISW::MouseButton> registeredMouseButtons;
    std::set<FISW::MouseWheel> registeredMouseWheels;

  public:
    EventHandlerSettings(   
      std::set<KeyboardKey> keyboardKeys = std::set<KeyboardKey>(), 
      std::set<MouseButton> mouseButtons = std::set<MouseButton>(), 
      std::set<MouseWheel> mouseWheels = std::set<MouseWheel>()
    );
    
    ~EventHandlerSettings();
    void join(const EventHandlerSettings& settings);
  
    friend class EventHandler;
  };
  
  
} 

#endif