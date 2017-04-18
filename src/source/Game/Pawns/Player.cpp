#include "..\..\..\headers\Game\Pawns\Player.h"
#include <iostream>
#include "../src/headers/Game/Resources.h"

const int NONE = 4, UP = 0, RIGHT = 1, LEFT = 2, DOWN = 3;

Player::Player() :
	Pawn("charMoveDown"),
	movingDirection(DOWN),
	velocity(200.f),
	coolDownTime(0.4f)
{
	usingTool = new Shovel;
}

Player::~Player()
{
	delete usingTool;
}

void Player::update(){
	input();
	float deltaTime = Resources::getDeltaTime();
	if (movingDirection == UP)
		move({0, deltaTime*-velocity});

	else if (movingDirection == DOWN)
		move({0, deltaTime * velocity});

	else if (movingDirection == LEFT)
		move({ deltaTime * -velocity, 0});

	else if (movingDirection == RIGHT)
		move({ deltaTime * velocity,0 });
}

void Player::input(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if(movingDirection != UP)
			setTexture("charMoveUp");
		movingDirection = UP;
		lookingDirection = movingDirection;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (movingDirection != LEFT)
			setTexture("charMoveLeft");
		movingDirection = LEFT;
		lookingDirection = movingDirection;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (movingDirection != DOWN)
			setTexture("charMoveDown");
		movingDirection = DOWN;
		lookingDirection = movingDirection;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (movingDirection != RIGHT)
			setTexture("charMoveRight");
		movingDirection = RIGHT;
		lookingDirection = movingDirection;
	}
	else
		movingDirection = NONE;

	
	if (useCoolDown.getElapsedTime().asSeconds() >= coolDownTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			useCoolDown.restart();
			float scale = Resources::getScale();

			sf::Vector2f position = getPosition();


			if (lookingDirection == LEFT)
				position += {-4 * scale, 8 * scale};

			else if (lookingDirection == RIGHT)
				position += {20 * scale, 8 * scale};

			else if (lookingDirection == UP)
				position += {8 * scale, -4 * scale};

			else if (lookingDirection == DOWN)
				position += {8 * scale, 20 * scale};

			
			position = ( position + sf::Vector2f(0.5,0.5) ) / (16 * scale);
			
			

			Tile *tile = Resources::getTile((sf::Vector2i)position);
			if (tile != nullptr)
				tile->use(usingTool, this);
		}
	}
	
}
