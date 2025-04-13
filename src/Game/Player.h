#pragma once

class Player
{
public:
	Player();
	~Player();

	const char* Username;

	float speed;
	
	float defaultsize = 30; 
	float size;

	sf::CircleShape Corps;

	sf::Vector2f GetPosition();

	void SetName(const char* _name);
	void SetSpeed(float _spd);
	void SetSize(float _siz);
	void Update(float deltaTime);

	bool CheckCollision(const sf::CircleShape& food);
};

