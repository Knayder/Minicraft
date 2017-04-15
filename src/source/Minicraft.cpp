#include "..\headers\Minicraft.h"





Minicraft::Minicraft(sf::RenderWindow & window) :
	window(window)
{
}

void Minicraft::run(){
	while (window.isOpen()) {
		input();
		window.clear(sf::Color::Green);
		window.display();
	}
}

void Minicraft::input(){
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}