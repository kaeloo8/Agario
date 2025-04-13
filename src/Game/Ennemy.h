#pragma once

class Ennemy
{
public:
	Ennemy();
	~Ennemy();

	const char* Username;

	float speed;

	float defaultsize = 30;
	float size;

	sf::CircleShape Corps;

	sf::Vector2f GetPosition();

	void SetName(const char* _name);
	void SetSpeed(float _spd);
	void Update(float deltaTime);
};

