#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP

#include <utility> // std::pair
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "GeometricVector.hpp"

namespace DIM {
  namespace Managers {

    class GraphicsManager {
    private:
      std::map<std::string, sf::Texture*> assets;
      sf::RenderWindow* window;
      sf::View view;
      Utility::VectorF camera_pos;
      Utility::VectorF camera_size;
      sf::Font font;
      const bool outOfSight(Utility::VectorF at, Utility::VectorF size) const;

    public:
      GraphicsManager();
      ~GraphicsManager();
      const bool loadAsset(const std::string& path);
      void draw(const std::string& id, Utility::VectorF at) const;
      void drawRect(Utility::VectorF at, Utility::VectorF size, int r, int g, int b) const;
      void drawTextCentered(const std::string& text, Utility::VectorF at, unsigned size) const;
      void centerCamera(Utility::VectorF at);
      sf::Window* getWindow() const;
      void display() const;
      void clear(int r, int g, int b) const;
      const Utility::VectorF getViewSize() const;
      const Utility::VectorF getMousePos() const;
      const Utility::VectorF getMousePosInView() const;
      const Utility::VectorF getSizeOfAsset(const std::string& id) const;

    };
    
  }
}

#endif