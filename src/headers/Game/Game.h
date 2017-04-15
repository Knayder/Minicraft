#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "..\TextureManager.h"
#include "Tile.h"

#include <vector>

class Game {
private:
	sf::RenderWindow &window;
	void input();
	std::vector<Tile> tiles;
	int scale;
public:
	Game(sf::RenderWindow &window);
	int run();
};

#endif GAME_H