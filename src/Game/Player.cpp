#include "pch.h"
#include "Player.h"

Player::Player()
{
	Corps.setRadius(defaultsize);
	Corps.setOrigin(defaultsize, defaultsize);
	Corps.setFillColor(sf::Color::Green);
	size = defaultsize;
}

Player::~Player()
{
}

sf::Vector2f Player::GetPosition()
{
	return sf::Vector2f(Corps.getPosition());
}

void Player::SetName(const char* _name)
{
	Username = _name;
}

void Player::SetSpeed(float _spd)
{
	speed = _spd;
}

void Player::SetSize(float _siz)
{
	size = _siz;
}

void Player::Update(float deltaTime)
{
	Corps.setRadius(size);
	Corps.setOrigin(size, size);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		Corps.move(-speed * deltaTime, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Corps.move(speed * deltaTime, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		Corps.move(0.0f, -speed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Corps.move(0.0f, speed * deltaTime);
	}
}

bool Player::CheckCollision(const sf::CircleShape& food)
{
	// Calculer la distance entre le centre du joueur et celui de la nourriture
	float distance = std::sqrt(
		std::pow(Corps.getPosition().x - food.getPosition().x, 2) +
		std::pow(Corps.getPosition().y - food.getPosition().y, 2)
	);

	// Vérifier si la distance est inférieure à la somme des rayons
	return distance < (Corps.getRadius() + food.getRadius());
}

