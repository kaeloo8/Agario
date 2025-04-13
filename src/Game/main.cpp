#include "pch.h"

sf::Vector2f Lerp(sf::Vector2f a, sf::Vector2f b, float t) {
	return a + (b - a) * t;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Clock clock;

	sf::View Camera;
	Camera.setSize(800, 600); // Taille de la vue

	// Zoom dynamique : plus le joueur est gros, plus la vue est grande
	float baseViewSize = 600.f; // taille de base de la caméra

	Player player;
	player.SetSpeed(150);
	
	std::vector<Food> Nouriture;

	for (int i = 0; i < 5000; i++)
	{
		Food I;
		Nouriture.push_back(I);
	}

	sf::Vector2f cameraPos = player.GetPosition(); // Position initiale

	sf::Event event;
	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		std::cout << player.size << std::endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.Update(deltaTime);

		// Lerp pour rendre le mouvement de caméra fluide
		sf::Vector2f targetPos = player.GetPosition();
		cameraPos = Lerp(cameraPos, targetPos, 5.f * deltaTime); // 5.f = facteur de réactivité
		float zoomFactor = player.size / 50.f; // plus la taille augmente, plus on dézoome

		Camera.setSize(800.f * zoomFactor, baseViewSize * zoomFactor);

		Camera.setCenter(cameraPos);
		window.setView(Camera);

		window.clear();
		window.draw(player.Corps);
		for (auto& M : Nouriture)
		{
			window.draw(M.Miam);
		}
		Nouriture.erase(
			std::remove_if(Nouriture.begin(), Nouriture.end(),
				[&](Food& M) {
					if (player.CheckCollision(M.Miam)) {
						float gain = M.Feedpoint / (player.size * 0.05f + 1.f); // Plus t'es gros, moins tu gagnes
						player.SetSize(player.size + gain);

						return true; // On le retire du vector
					}
					return false;
				}),
			Nouriture.end()
		);

		window.display();
	}

	return 0;
}
