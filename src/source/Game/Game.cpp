#include "..\..\headers\Game\Game.h"
#include <Windows.h>
Game::~Game()
{
	TextureManager::clear();
}


void Game::loadResources()
{
	TextureManager::load("res/texture.png", { 16,16 }, true, sf::Color(0,0,0));
}


Game::Game(sf::RenderWindow & window) :
	window(window),
	scale(4.f),
	maxFps(60)
{
	Resources::setScale(scale);

	loadResources(); //Load resources

	player = new Player();
	player->setScale(scale, scale);
	Resources::addPawn(player);
}



int Game::run(){
	std::vector<std::vector<int>> map = {
		{ 11,7,7,7,7,7,7,7,7,7,7,7,10 },
		{ 8,4,4,4,4,4,4,4,4,4,4,4,6 },
		{ 8,4,4,4,4,4,4,4,4,4,4,4,6 },
		{ 8,4,4,4,4,4,4,4,4,4,4,4,6 },
		{ 8,4,4,4,4,4,4,4,4,4,4,4,6 },
		{ 8,4,4,4,4,4,4,4,4,4,4,4,6 },
		{ 8,4,4,4,4,4,4,4,4,4,4,4,6 },
		{ 12,5,5,5,5,5,5,5,5,5,5,5,9 }
	};
	Resources::setMap(map);

	clock.restart();
	float deltaTime = 1.f / 60.f;

	while (window.isOpen()) {
		//FPS display per 1 sec
		if (clock2.getElapsedTime().asSeconds() >= 1) {
			clock2.restart();
			std::cout << "FPS: " << (int)((1 / deltaTime)+0.5) << std::endl;
		}

		//FPS locked at "maxFps"
		if (clock.getElapsedTime().asSeconds() >= 1.f / maxFps) {
			//DeltaTime
			deltaTime = clock.restart().asSeconds();
			Resources::setDeltaTime(deltaTime);
			//Start
			input();

			Resources::update();

			window.clear(sf::Color::Yellow);

			Resources::draw(window);

			window.display();
			
		}
	}
	return 0;
}

void Game::input() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}



