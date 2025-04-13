#include "pch.h"
#include "Food.h"

Food::Food()
{
	Feedpoint = std::rand() % 10 + 1; // pour éviter Feedpoint = 0
	Miam.setRadius(Feedpoint);
	Miam.setOrigin(Feedpoint, Feedpoint);
	Miam.setPosition(std::rand() % 10000 - 5000, std::rand() % 10000 - 5000);

	int Color = std::rand() % 5;
	switch (Color)
	{
	case 0:
		Miam.setFillColor(sf::Color::Red);
		break;
	case 1:
		Miam.setFillColor(sf::Color::Green);
		break;
	case 2:
		Miam.setFillColor(sf::Color::Blue);
		break;
	case 3:
		Miam.setFillColor(sf::Color::Yellow);
		break;
	case 4:
		Miam.setFillColor(sf::Color(255, 105, 180)); // rose
		break;
	default:
		Miam.setFillColor(sf::Color::White);
		break;
	}
}


Food::~Food()
{
}
