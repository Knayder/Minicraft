#ifndef UTILITY_H
#define UTILITY_H

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

	virtual void update(const float &deltaTime){}
};


#endif UTILITY_H