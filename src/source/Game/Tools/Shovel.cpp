#include "..\..\..\headers\Game\Tools\Shovel.h"

Shovel::Shovel() :
	Tool("shovel")
{
}

void Shovel::use(const Pawn & user)
{
	sf::err() << "Hello";
}

void Shovel::update(const float & deltaTime)
{
	sf::err() << "Hello";
}

