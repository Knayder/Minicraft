#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "../TextureManager.h"

class Tile : public sf::Sprite {
public:
	Tile(const std::string &textureName);
	virtual void tick(); //tick(tool &usedTool)
};

#endif TILE_H