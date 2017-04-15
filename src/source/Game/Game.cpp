#include "..\..\headers\Game\Game.h"

Game::Game(sf::RenderWindow & window) :
	window(window)
{
	//TextureManager::load("../../../res/obraz.jpg", "test");
}

int Game::run(){
	//Tile tile("test");
	while (window.isOpen()) {
		input();
		window.clear(sf::Color::Yellow);
		//window.draw(tile);
		window.display();
	}
	return 0;
}

void Game::input() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
