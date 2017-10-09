// SFMLtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Particles.h"
#include <SFML/Graphics.hpp>

using namespace std;

void draw(sf::Sprite &sprite, sf::RenderWindow &window, sf::Text &text) {
	window.clear();
	window.draw(sprite);
	window.draw(text);
	window.display();
}



int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(512, 256), "Particles");

	// create the particle system
	ParticleSystem particles(1000);

	// create a clock to track the elapsed time
	sf::Clock clock;

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// make the particle system emitter follow the mouse
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		particles.setEmitter(window.mapPixelToCoords(mouse));

		
		// update it
		sf::Time elapsed = clock.restart();
		particles.update(elapsed);

		// draw it
		window.clear();
		window.draw(particles);
		window.display();
	}

	return 0;
}


