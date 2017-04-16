#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include "Utility.h"
#include "../TextureManager.h"



class Pawn : public Utility {
public:
	Pawn(const std::string &name):
		Utility(name)
	{}
	virtual ~Pawn(){}
	
	virtual void update(const float &deltaTime) override {}
};




#endif PAWN_H