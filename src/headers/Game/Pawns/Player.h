#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Pawn.h"

class Player : public Pawn {
	int movingDirection;
	float velocity;

	sf::Clock useCoolDown;
	float coolDownTime;
public:
	Player();
	virtual void update() override;
	void input();
};

#endif PLAYER_H