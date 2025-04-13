#include "pch.h"
#include "Ennemy.h"
Ennemy::Ennemy()
{
	Corps.setRadius(defaultsize);
	Corps.setFillColor(sf::Color::Green);
}

Ennemy::~Ennemy()
{
}

sf::Vector2f Ennemy::GetPosition()
{
	return sf::Vector2f(Corps.getPosition());
}

void Ennemy::SetName(const char* _name)
{
	Username = _name;
}

void Ennemy::SetSpeed(float _spd)
{
	speed = _spd;
}

void Ennemy::Update(float deltaTime)
{
}
