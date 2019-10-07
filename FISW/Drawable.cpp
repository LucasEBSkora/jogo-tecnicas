#include "Drawable.h"

#include <functional>
#include <iostream>

namespace FISW {

Drawable::Drawable(const char* Path, float X, float Y, float Length, float Height)
    : path { Path }
    , x { X }
    , y { Y }
    , length { Length }
    , height { Height }
    , texture { nullptr }
    , box { sf::Vector2f(Length, Height) } {

    box.setPosition(X, Y);
}

Drawable::~Drawable() {
}

// returns a list containing only the texture
std::list<const char*> Drawable::getAssetPathList() const {
    std::list<const char*> list;
    list.push_back(path);
    return list;
}

// // As this class doesn't depend on any events, returns an enpty settings object
// this class depends on update and draw events
EventHandlerSettings Drawable::getSettings() {
    // it can be done either way:
    // with lambdas
    auto update_fun = [this](float time) { update(time); };
    // std::function<void(float)> update = std::bind(static_cast<void(Drawable::*)(float)>(&Drawable::update), this,
    // std::placeholders::_1);

    // with std::bind
    auto draw_fun = std::bind(&Drawable::draw, this, std::placeholders::_1);

    EventHandlerSettings settings;
    settings.addUpdate(update_fun);
    settings.addDraw(draw_fun);
    return settings;
}

// Finds the asset in the map using the path as a key, returns 1 if it isn't able to
int Drawable::init(std::map<std::string, sf::Texture*> assets) {

    if (assets.find(path) == assets.end()) {
        std::cout << "error! asset " << path << "could not be initialized properly!\n";
        return 1;
    }

    texture = assets[path];

    box.setTexture(texture, true);

    return 0;
}

// For now it just moves the image
void Drawable::update(float time) {
    box.move(sf::Vector2f(time * 40.0f, time * 20.0f));
}

// No need to comment
void Drawable::draw(sf::RenderWindow* window) {
    window->draw(box);
}

} // namespace FISW