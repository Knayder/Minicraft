#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "../TextureManager.h"
#include "Entity.h"

class Tool;
class Pawn;

class Tile : public Entity {
public:
	Tile(const int &index) :
		Entity(index)
	{}
	virtual void use(Tool *tool, Pawn *pawn){}
	virtual void update() override{}
};

#endif TILE_H