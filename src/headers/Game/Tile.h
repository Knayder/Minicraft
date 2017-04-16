#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "../TextureManager.h"
#include "Utility.h"

class Tool;
class Pawn;

class Tile : public Utility {
public:
	Tile(const std::string &name) :
		Utility(name)
	{

	}
	virtual void use(Tool &tool, Pawn &pawn){}
	virtual void update(const float &deltaTime){}
};

#endif TILE_H