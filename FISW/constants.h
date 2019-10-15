#include "SFML/Graphics.hpp"

namespace FISW {

typedef sf::Keyboard::Key KeyboardKey;
typedef sf::Mouse::Button MouseButton;
typedef sf::Mouse::Wheel MouseWheel;

// shamelessly copied from SFML
namespace WindowStyle {

  enum {
    None       = 0,      ///< No border / title bar (this flag and all others are mutually exclusive)
    Titlebar   = 1 << 0, ///< Title bar + fixed border
    Resize     = 1 << 1, ///< Title bar + resizable border + maximize button
    Close      = 1 << 2, ///< Title bar + close button
    Fullscreen = 1 << 3, ///< Fullscreen mode (this flag and all others are mutually exclusive)

    Default = Titlebar | Resize | Close ///< Default window style
  };
}

} // namespace FISW