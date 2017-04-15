#include "..\..\headers\Game\Game.h"

Game::Game(sf::RenderWindow & window) :
	window(window),
	scale(6)
{
	TextureManager::load("res/sheet.png", "texture");
	TextureManager::removeColor("texture", sf::Color(0, 0, 0));

	TextureManager::load("texture", "charMoveDown", sf::IntRect(0, 0, 16, 16));
	TextureManager::load("texture", "charMoveUp",sf::IntRect(16, 0, 16, 16));
	TextureManager::load("texture", "charLookRight", sf::IntRect(32, 0, 16, 16));
	TextureManager::load("texture", "charMoveRight", sf::IntRect(48, 0, 16, 16));
	TextureManager::load("texture", "grass", sf::IntRect(64, 0, 8, 8));

	TextureManager::setColor("charMoveDown", 80, sf::Color(30, 30, 30));
	TextureManager::setColor("charMoveDown", 170, sf::Color(135, 66, 66));
	TextureManager::setColor("charMoveDown", 250, sf::Color(209, 173, 146));

	TextureManager::setColor("charMoveUp", 80, sf::Color(30, 30, 30));
	TextureManager::setColor("charMoveUp", 170, sf::Color(135, 66, 66));
	TextureManager::setColor("charMoveUp", 250, sf::Color(209, 173, 146));

	TextureManager::setColor("charLookRight", 80, sf::Color(30, 30, 30));
	TextureManager::setColor("charLookRight", 170, sf::Color(135, 66, 66));
	TextureManager::setColor("charLookRight", 250, sf::Color(209, 173, 146));

	TextureManager::setColor("charMoveRight", 80, sf::Color(30, 30, 30));
	TextureManager::setColor("charMoveRight", 170, sf::Color(135, 66, 66));
	TextureManager::setColor("charMoveRight", 250, sf::Color(209, 173, 146));

	TextureManager::setColor("grass", 80, sf::Color(30, 200, 20));
	TextureManager::setColor("grass", 170, sf::Color(50, 170, 20));
	TextureManager::setColor("grass", 250, sf::Color(20, 230, 30));

	
}

int Game::run(){

	for (int y = 0; y < 720/(8*scale); y++)
		for (int x = 0; x < 1280/(8*scale)+1; x++) {
			Tile tile("grass");
			tile.setPosition(x * 8 * scale, y * 8 * scale);
			tile.setScale(scale, scale);
			tiles.push_back(tile);
		}
	while (window.isOpen()) {
		input();
		window.clear(sf::Color::Yellow);
		for (auto tile : tiles)
			window.draw(tile);
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
