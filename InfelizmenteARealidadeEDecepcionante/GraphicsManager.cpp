#include "GraphicsManager.hpp"

#include <vector>
#include <iostream>
#include <algorithm>

namespace DIM {
  int GraphicsManager::next_uid = 0;

  GraphicsManager::GraphicsManager() {
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    int width = modes[0].width * .7;
    int height = modes[0].height * .7;
    window->create(sf::VideoMode(width, height), "Game");

    camera_size = VectorF(width, height);
  }

  GraphicsManager::~GraphicsManager() {
    for (auto i = assets.begin();
         i != assets.end();
         ++i) {
      delete (i->second).first;
    }
    assets.clear();
  }

  int GraphicsManager::loadAsset(const char* path) {
    auto it = assets.find(path);
    if(it != assets.end()) {
      return it->second.second;
    } else {
      sf::Texture* texture = new sf::Texture();
      if (!texture->loadFromFile(path)) {
        std::cout << "e morreu\n";
        exit(1234);
      } 
      assets.insert(std::make_pair(texture, next_uid));
      ++next_uid;
    }
  }

  void GraphicsManager::draw(int id, VectorF at) const {
    sf::Texture* texture;
    auto it = std::find(assets.begin(), assets.end(), [id] (auto i) { return i->second == id });
    if (it == assets.end()) {
      std::cout << "morreu porque tentou desenhar algo nao criado\n";
      exit(1235);
    }
    texture = it->second.first;
    sf::Vector2u size = texture->getSize();
    
    if (!outOfSight(at, VectorF(size.x, size.y))) {
      at -= camera_pos;
      sf::Sprite sprite;
      sprite.setTexture(*texture);
      sprite.setPosition(at.x, at.y);
      window->draw(sprite);
    }

  }

  void GraphicsManager::centerCamera(VectorF at) {
    camera_pos = at - camera_size * .5;
  }

  bool GraphicsManager::outOfSight(VectorF at, VectorF size) const {
    return (at.x + size.x < camera_pos.x ||
            at.y - size.y < camera_pos.y || // y cresce para baixo? //é pra ser //blz
            at.x > camera_pos.x + camera_size.x ||
            at.y > camera_pos.y + camera_size.y);
  }

}