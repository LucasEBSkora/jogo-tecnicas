#include "EventHandler.h"

#include <iostream>
#include <string>

namespace FISW {
const sf::Time EventHandler::timePerFrame = sf::seconds(1.0f / 60.0f);

EventHandler::EventHandler(EventHandlerSettings Settings)
    : settings { Settings }
    , timeSinceLastUpdate { sf::Time::Zero } {
}

EventHandler::~EventHandler() {
}

void EventHandler::updateSettings(EventHandlerSettings Settings) {
    settings = Settings;
}

const EventReport& EventHandler::processEvents(sf::RenderWindow* window) {

    sf::Time elapsedTime = clock.restart();
    report.passedTime    = elapsedTime.asSeconds();
    timeSinceLastUpdate += elapsedTime;

    while (timeSinceLastUpdate > timePerFrame) {
        timeSinceLastUpdate -= timePerFrame;
        sf::Event evnt;
        while (window->pollEvent(evnt)) {

            if (evnt.type == sf::Event::Closed) {

                std::cout << "close button pressed!" << std::endl;
                report.closeGame = true;

            } else if (evnt.type == sf::Event::TextEntered) {
                if (evnt.text.unicode < 128)
                    std::cout << static_cast<char>(evnt.text.unicode) << std::flush;
            }
        }
        // update things
        for (auto f : settings.updates) {
            f(timePerFrame.asSeconds());
        }
    }
    // draw things
    window->clear();
    for (auto f : settings.draws) {
        f(window);
    }
    window->display();
    return report;
}

void EventHandler::resetTime() {
    timeSinceLastUpdate = sf::Time::Zero;
}

} // namespace FISW