#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "../TextureManager.h"

class Tool;
class Pawn;

class Tile : public sf::Sprite {
public:
	Tile(const std::string &textureName);
	void setTexture(const std::string &name);
	virtual void use(Tool &tool, Pawn &pawn){}
};

#endif TILE_H