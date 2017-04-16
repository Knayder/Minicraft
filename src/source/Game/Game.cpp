#include "..\..\headers\Game\Game.h"
#include <Windows.h>
Game::~Game()
{
	TextureManager::clear();
	for (auto tile : tiles)
		delete tile;
}


void Game::loadResources()
{
	TextureManager::load("res/sheet.png", "texture");
	TextureManager::removeColor("texture", sf::Color(0, 0, 0));

	TextureManager::load("texture", "charMoveDown", sf::IntRect(0, 0, 16, 16));
	TextureManager::load("texture", "charMoveUp", sf::IntRect(16, 0, 16, 16));
	TextureManager::load("texture", "charLookRight", sf::IntRect(32, 0, 16, 16));
	TextureManager::load("texture", "charMoveRight", sf::IntRect(48, 0, 16, 16));
	TextureManager::load("texture", "grass", sf::IntRect(64, 0, 16, 16));
	TextureManager::load("texture", "grassDown", sf::IntRect(80, 0, 16, 16));
	TextureManager::load("texture", "grassDownRight", sf::IntRect(96, 0, 16, 16));
	TextureManager::load("texture", "grassDownRight2", sf::IntRect(112, 0, 16, 16));

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

	TextureManager::setColor("grass", 80, sf::Color(30, 100, 20));
	TextureManager::setColor("grass", 170, sf::Color(30, 90, 20));
	TextureManager::setColor("grass", 250, sf::Color(30, 80, 20));

	TextureManager::setColor("grassDown", 80, sf::Color(30, 100, 20));
	TextureManager::setColor("grassDown", 170, sf::Color(30, 90, 20));
	TextureManager::setColor("grassDown", 250, sf::Color(30, 80, 20));

	TextureManager::setColor("grassDownRight", 80, sf::Color(30, 100, 20));
	TextureManager::setColor("grassDownRight", 170, sf::Color(30, 90, 20));
	TextureManager::setColor("grassDownRight", 250, sf::Color(30, 80, 20));

	TextureManager::setColor("grassDownRight2", 80, sf::Color(30, 100, 20));
	TextureManager::setColor("grassDownRight2", 170, sf::Color(30, 90, 20));
	TextureManager::setColor("grassDownRight2", 250, sf::Color(30, 80, 20));

	TextureManager::load("grassDownRight", "grassDownLeft", 90);
	TextureManager::load("grassDownLeft", "grassUpLeft", 90);
	TextureManager::load("grassUpLeft", "grassUpRight", 90);

	TextureManager::load("grassDown", "grassLeft", 90);
	TextureManager::load("grassLeft", "grassUp", 90);
	TextureManager::load("grassUp", "grassRight", 90);

	TextureManager::load("grassDownRight2", "grassDownLeft2", 90);
	TextureManager::load("grassDownLeft2", "grassUpLeft2", 90);
	TextureManager::load("grassUpLeft2", "grassUpRight2", 90);
}


Game::Game(sf::RenderWindow & window) :
	window(window),
	scale(4)
{
	loadResources();
}



int Game::run(){
	std::vector<std::vector<std::string>> map = {
		{"grassUpLeft", "grassUp", "grassUp", "grassUp", "grassUp", "grassUp", "grassUp", "grassUp" , "grassUp" , "grassUp" , "grassUp", "grassUpRight"},
		{"grassLeft", "grass" , "grass", "grass", "grass", "grass", "grass", "grass" , "grass" , "grass" , "grass", "grassRight"},
		{ "grassLeft", "grass" , "grass", "grass", "grass", "grass", "grass", "grass" , "grass" , "grass" , "grass", "grassRight" },
		{ "grassLeft", "grass" , "grass" , "grass", "grass", "grass", "grass", "grass", "grass" , "grass" , "grass", "grassRight" },
		{ "grassLeft", "grass" , "grass" , "grass", "grass", "grass", "grass", "grass", "grass" , "grass" , "grassDownRight2", "grassDownRight" },
		{ "grassLeft", "grass" , "grass", "grass", "grass", "grass","grass", "grass" , "grass" , "grass" , "grassDownRight" },
		{ "grassDownLeft", "grassDown" ,"grassDown" ,"grassDown" ,"grassDown" ,"grassDown" ,"grassDown" , "grassDown" , "grassDown" , "grassDownRight" },
	};
	for (int y = 0; y < map.size(); y++)
		for (int x = 0; x < map[y].size(); x++) 
			addTile(new GrassTile(map[y][x]), {16.f*x*scale, 16.f*y*scale});

	while (window.isOpen()) {
		input();
		window.clear(sf::Color::Yellow);
		for (auto tile : tiles)
			window.draw(*tile);
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
void Game::addTile(Tile * tile, const sf::Vector2f & position) {
	tile->setScale(scale, scale);
	tile->setPosition(position);
	tiles.push_back(tile);
}


