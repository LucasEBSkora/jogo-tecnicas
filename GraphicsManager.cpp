#include "GraphicsManager.hpp"

#include <vector>
#include <iostream>
#include <algorithm>

namespace DIM {

  GraphicsManager::GraphicsManager() {
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    unsigned width = modes[0].width * .7;
    unsigned height = modes[0].height * .7;
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Game");
    window->setKeyRepeatEnabled(false);
    width = 600;
    height = width / 16 * 9;
    view = sf::View(sf::FloatRect(0, 0, width, height));
    window->setView(view);
    font.loadFromFile("assets/CantoraOne-Regular.ttf");

    camera_size = VectorF(width, height);
  }

  GraphicsManager::~GraphicsManager() {
    for (auto i = assets.begin();
         i != assets.end();
         ++i) {
      delete i->second;
    }
    assets.clear();
  }

  bool GraphicsManager::loadAsset(const std::string& path) {
    auto it = assets.find(path);
    if(it != assets.end()) {
      return true;
    } else {
      sf::Texture* texture = new sf::Texture();
      if (!texture->loadFromFile(path)) {
        std::cout << "e morreu\n";
        exit(1234);
      } 
      assets.emplace(path, texture);
      return true;
    }
  }

  void GraphicsManager::draw(const std::string& id, VectorF at) const {
    
    sf::Texture* texture;
    auto it = assets.find(id);
    if (it == assets.end()) {
      std::cout << "morreu porque tentou desenhar algo nao criado: \n" << id;
      exit(1235);
    }
    texture = it->second;
    sf::Vector2u size = texture->getSize();
    
    if (!outOfSight(at, VectorF(size.x, size.y))) {
      at -= camera_pos;
      sf::Sprite sprite;
      sprite.setTexture(*texture);
      sprite.setPosition(at.x, at.y);
      window->draw(sprite);
    }

  }

  void GraphicsManager::drawRect(VectorF at, VectorF size, int r, int g, int b) const {
    if (!outOfSight(at, size)) {
      at -= camera_pos;
      sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(size.x, size.y));
      
      rect.setFillColor(sf::Color(r, g, b));
      rect.setPosition(at.x, at.y);
      window->draw(rect);
    }
  }

  void GraphicsManager::drawTextCentered(const std::string& text, VectorF at, unsigned size) const {
    sf::Text txt = sf::Text(text, font);
    txt.setCharacterSize(size);
    txt.setFillColor(sf::Color::White);
    sf::FloatRect bounding = txt.getGlobalBounds();
    txt.setOrigin(bounding.width / 2, bounding.height / 2);
    txt.setPosition(at.x, at.y);
    // if (text == "Exit Game") {
    //   std::cout << at.x << ' ' << at.y << ' ' << bounding.width << ' ' << bounding.height << ' ' << getMousePosInView().x << ' ' << getMousePosInView().y << std::endl;
    // }
    window->draw(txt);
  }

  void GraphicsManager::centerCamera(VectorF at) {
    camera_pos = at - camera_size * .5;
  }

  bool GraphicsManager::outOfSight(VectorF at, VectorF size) const {
    return (at.x + size.x < camera_pos.x ||
            at.y + camera_size.y < camera_pos.y || // y cresce para baixo? //é pra ser //blz
            at.x > camera_pos.x + camera_size.x ||
            at.y > camera_pos.y + camera_size.y);
  }

  sf::Window* GraphicsManager::getWindow() const {
    return window;
  }

  void GraphicsManager::display() const {
    window->display();
  }

  void GraphicsManager::clear(int r, int g, int b) const {
    window->clear(sf::Color(r, g, b));
  }

  VectorF GraphicsManager::getViewSize() const {
    return camera_size;
  }

  VectorF GraphicsManager::getMousePos() const {
    sf::Vector2i pos = sf::Mouse::getPosition(*window);
    return VectorF(pos.x, pos.y);
  }

  VectorF GraphicsManager::getMousePosInView() const {
    sf::Vector2i pos = sf::Mouse::getPosition(*window);
    sf::Vector2u window_size = window->getSize();
    return VectorF(pos.x / static_cast<float>(window_size.x) * camera_size.x, pos.y / static_cast<float>(window_size.y) * camera_size.y) + camera_pos;
  }

  VectorF GraphicsManager::getSizeOfAsset(const std::string& id) const {
    sf::Texture* texture;
    auto it = assets.find(id);
    if (it == assets.end()) {
      std::cout << "morreu porque tentou desenhar algo nao criado\n";
      exit(1235);
    }
    texture = it->second;
    sf::Vector2u size = texture->getSize();
    return VectorF(size.x, size.y);
  }
}