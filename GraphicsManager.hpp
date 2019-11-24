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
      Utils::VectorF camera_pos;
      Utils::VectorF camera_size;
      sf::Font font;
      const bool outOfSight(Utils::VectorF at, Utils::VectorF size) const;

    public:
      GraphicsManager();
      ~GraphicsManager();
      const bool loadAsset(const std::string& path);
      void draw(const std::string& id, Utils::VectorF at) const;
      void drawRect(Utils::VectorF at, Utils::VectorF size, int r, int g, int b) const;
      void drawTextCentered(const std::string& text, Utils::VectorF at, unsigned size) const;
      void centerCamera(Utils::VectorF at);
      sf::Window* getWindow() const;
      void display() const;
      void clear(int r, int g, int b) const;
      const Utils::VectorF getViewSize() const;
      const Utils::VectorF getMousePos() const;
      const Utils::VectorF getMousePosInView() const;
      const Utils::VectorF getSizeOfAsset(const std::string& id) const;

    };
    
  }
}

#endif