#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Pawn.h"
#include "../Tool.h"
#include "../Tools/Shovel.h"
#include <cmath>

class Player : public Pawn {
	int movingDirection;
	int lookingDirection;
	float velocity;

	sf::Clock useCoolDown;
	float coolDownTime;

	Tool *usingTool;
public:
	Player();
	~Player();
	virtual void update() override;
	void input();
};

#endif PLAYER_H