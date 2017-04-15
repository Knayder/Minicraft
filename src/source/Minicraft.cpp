#include "..\headers\Minicraft.h"





Minicraft::Minicraft(sf::RenderWindow & window) :
	window(window),
	backgroundColor(37,37,48),
	game(window)
{
}

void Minicraft::run(){
	game.run();
}

