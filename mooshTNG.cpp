#include "mooshTNG.hpp"
#include <SFML/Graphics.hpp>

void MooshTNG_Project::exec() {
	sf::Clock clock;
	sf::Time timer;
	sf::Vector2f windowSize(1000, 700);
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Moosh - The Next Generation");
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				window.close();
			}
			if (event.type == sf::Event::KeyReleased) {}
		}
		if ((clock.getElapsedTime().asMilliseconds() - timer.asMilliseconds()) > 16.6) {
			timer = clock.getElapsedTime();
		}

		window.clear(sf::Color::Black);
		window.display();
	}
}