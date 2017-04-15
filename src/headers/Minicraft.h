#ifndef MINICRAFT_H
#define MINICRAFT_H

#include <SFML/Graphics.hpp>
#include "Game\Game.h"

class Minicraft {
private:
	sf::RenderWindow &window;

	sf::Color backgroundColor;

	Game game;
public:
	Minicraft(sf::RenderWindow &window);
	void run();

};


#endif MINICRAFT_H