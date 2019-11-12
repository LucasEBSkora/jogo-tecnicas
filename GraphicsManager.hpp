#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP

#include <utility> // std::pair
#include <map>
#include <SFML/Graphics.hpp>
#include "Vector.hpp"

namespace DIM {

  class GraphicsManager {
  
  private:
    std::map<const char*, sf::Texture*> assets;
    sf::RenderWindow* window;
    VectorF camera_pos;
    VectorF camera_size;

    bool outOfSight(VectorF at, VectorF size) const;

  public:
    GraphicsManager();
    ~GraphicsManager();
    bool loadAsset(const char* path);
    void draw(const char* id, VectorF at) const;
    void drawRect(VectorF at, VectorF size, int r, int g, int b) const;
    void centerCamera(VectorF at);
    sf::Window* getWindow() const;
    void display() const;
    void clear(int r, int g, int b) const;
    VectorF getViewSize() const;
  
  };

}

#endif // GRAPHICSMANAGER_HPP