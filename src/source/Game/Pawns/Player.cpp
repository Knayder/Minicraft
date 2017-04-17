#include "..\..\..\headers\Game\Pawns\Player.h"
#include <iostream>

const int NONE = 4, UP = 0, RIGHT = 1, LEFT = 2, DOWN = 3;

Player::Player() :
	Pawn("charMoveDown"),
	movingDirection(DOWN),
	velocity(200),
	coolDownTime(0.7)
{

}

void Player::update(const float & deltaTime){
	input();
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
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (movingDirection != LEFT)
			setTexture("charMoveLeft");
		movingDirection = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (movingDirection != DOWN)
			setTexture("charMoveDown");
		movingDirection = DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (movingDirection != RIGHT)
			setTexture("charMoveRight");
		movingDirection = RIGHT;
	}
	else
		movingDirection = NONE;
	if (useCoolDown.getElapsedTime().asSeconds() >= coolDownTime) {
		useCoolDown.restart();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			std::cout << "USE" << std::endl;
	}
	
}
