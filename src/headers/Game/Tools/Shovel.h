#ifndef SHOVEL_H
#define SHOVEL_H

#include "../Tool.h"
#include "../Pawn.h"

class Shovel : public Tool {
public:
	Shovel();

	virtual void use(const Pawn& user) override;
	virtual void update(const float &deltaTime) override;
};


#endif SHOVEL_H