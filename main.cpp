#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	std::cout << "lol" << std::endl;
	sf::RenderWindow	window;
	window.create(sf::VideoMode(900, 800), "This is a test");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Green);
		window.display();
	}

}