#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "../TextureManager.h"



class Pawn : public Entity {
public:
	Pawn(const int &index):
		Entity(index)
	{}
	virtual ~Pawn(){}
	
	virtual void update() override {}
};




#endif PAWN_H