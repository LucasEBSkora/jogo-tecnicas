#include "Player.h"
#include <iostream>




Player::Player( sf::Texture * texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(200.0f, 200.0f));
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("walk2.png");
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		std::cout<<"wtf\n";
		movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		std::cout<<"ftw\n";
		
		movement.x += speed * deltaTime;
	}
	
	
	
	if (movement.x >= 0.f) faceRight = true;
	else faceRight = false;

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void Player::Draw(sf::RenderWindow *window)
{
	window->draw(body);
}
