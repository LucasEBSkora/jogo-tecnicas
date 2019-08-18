// SFML.cpp : define o ponto de entrada para o aplicativo do console.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"

static const float VIEW_HEIGHT = 600;

void ResizeView(const sf::RenderWindow *window, sf::View *view) {
	float aspectRatio = (float)window->getSize().x / window->getSize().y;
	view->setSize(VIEW_HEIGHT*aspectRatio, VIEW_HEIGHT);
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, VIEW_HEIGHT), "SFML tutorial", sf::Style::Close | sf::Style::Resize);
	//sf::RectangleShape player(sf::Vector2f(200.0f, 200.0f));
	
	sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(800.0f, VIEW_HEIGHT));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("walk2.png");
	//player.setTexture(&playerTexture);

//	sf::Vector2u textureSize = playerTexture.getSize();
	//textureSize.x /= 9;

	//player.setTextureRect(sf::IntRect(textureSize.x * 0, 0, textureSize.x, textureSize.y));

	Player player = Player(&playerTexture, sf::Vector2u(9, 1), 0.11f, 32.f);

	float deltaTime = 0.0f;
	sf::Clock clock;
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;

		while (window.pollEvent(evnt)) {
			
			if (evnt.type == sf::Event::Closed) {
				window.close();
			}
			else if (evnt.type == sf::Event::Resized) {
				ResizeView(&window, &view);
			}
			else if (evnt.type == sf::Event::TextEntered) {
				if (evnt.text.unicode < 128)
					printf("%c", evnt.text.unicode);
					
			}
		}

			/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				player.setPosition((float)mouse.x, (float)mouse.y);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
				player.move(-3,0);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				player.move(3, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
				player.move(0, -3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
				player.move(0, 3);
			}*/

			player.Update(deltaTime);
			window.clear();
			view.setCenter(player.GetPosition());
			window.setView(view);
			player.Draw(&window);
			
			window.display();

	}
	return 0;
}

void ResizeVIew(const sf::RenderWindow * window, sf::View * view)
{
}
