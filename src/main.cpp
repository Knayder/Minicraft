#include <SFML/Graphics.hpp>
#include "headers\Minicraft.h"
int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Minicraft", sf::Style::Close , settings);

	Minicraft minicraft(window);
	minicraft.run();
	return 0;
}