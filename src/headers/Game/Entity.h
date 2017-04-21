#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "../TextureManager.h"

class Entity : public sf::Sprite {
public:
	Entity(const int &index)
	{
		setTexture(index);
			
	}
	void setTexture(const int &index) {
		sf::Texture *texture = TextureManager::get(index);
		if (texture != nullptr)
			sf::Sprite::setTexture(*texture);
	}

	virtual void update(){}
};


#endif ENTITY_H