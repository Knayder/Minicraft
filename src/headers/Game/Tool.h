#ifndef TOOL_H
#define TOOL_H

#include "Entity.h"
#include "Pawn.h"
#include <SFML/Graphics.hpp>

class Tool : public Entity {
public:
	Tool(const std::string &name) :
		Entity(name)
	{}
	virtual void use(const Pawn &user){}
	virtual void update(const float &deltaTime);
};

#endif TOOL_H