#include "..\..\headers\Game\Tile.h"

Tile::Tile(const std::string &textureName)
{
	sf::Texture *texture = TextureManager::get(textureName);
	sf::Sprite::setTexture(*texture);
}

void Tile::setTexture(const std::string & name)
{
	sf::Sprite::setTexture(*TextureManager::get(name));
}
