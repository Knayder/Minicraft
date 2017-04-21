#ifndef TOOL_H
#define TOOL_H

#include "Entity.h"
#include "Pawn.h"
#include <SFML/Graphics.hpp>

class Tool : public Entity {
public:
	Tool(const int &index) :
		Entity(index)
	{}
	virtual void use(const Pawn &user){}
	virtual void update() override {}
};

#endif TOOL_H