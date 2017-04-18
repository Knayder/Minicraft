#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "../TextureManager.h"

class Entity : public sf::Sprite {
public:
	Entity(const std::string &name) :
		sf::Sprite(*TextureManager::get(name))
	{
		
	}
	void setTexture(const std::string &name) {
		sf::Sprite::setTexture(*TextureManager::get(name));
	}

	virtual void update(){}
};


#endif ENTITY_H