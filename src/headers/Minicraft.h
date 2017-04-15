#ifndef MINICRAFT_H
#define MINICRAFT_H

#include <SFML/Graphics.hpp>

class Minicraft {
private:
	sf::RenderWindow &window;
	void input();
public:
	Minicraft(sf::RenderWindow &window);
	void run();

};


#endif MINICRAFT_H