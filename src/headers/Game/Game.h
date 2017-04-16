#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "..\TextureManager.h"
#include "Tile.h"
#include "Tiles/GrassTile.h"
#include "Pawns/Player.h"

#include <iostream>

#include <vector>

class Game {
private:
	sf::RenderWindow &window;
	void input();
	void addTile(Tile *tile, const sf::Vector2f &position);
	std::vector<Tile*> tiles;
	void loadResources();
	int scale;
	float maxFps;

	sf::Clock clock, clock2;
	Pawn *player;
public:
	Game(sf::RenderWindow &window);
	~Game();
	int run();
};

#endif GAME_H