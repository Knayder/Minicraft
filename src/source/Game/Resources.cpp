#include "..\..\headers\Game\Resources.h"

Resources & Resources::getInstance(){
	static Resources instance;
	return instance;
}

Resources::~Resources() {
	for (auto vector : map)
		for (auto tile : vector)
			delete tile;

	for (auto pawn : pawns)
		delete pawn;
}

Tile * Resources::newTile(Tile *tile, const sf::Vector2f & position, const float &scale)
{
	tile->setPosition(position);
	tile->setScale(scale, scale);
	return tile;
}

void Resources::setMap(const std::vector<std::vector<std::string>>& newMap, const float &scale)
{
	Resources &instance = Resources::getInstance();
	Resources::clearMap();

	instance.map.resize(newMap.size());
	for (int y = 0; y < newMap.size(); y++) {
		instance.map[y].resize(newMap[y].size());
		for (int x = 0; x < newMap[y].size(); x++) {
			instance.map[y][x] = Resources::newTile(new GrassTile(newMap[y][x]), {scale*x*16, scale*y*16}, scale);
		}
	}
}

void Resources::clearMap()
{
	Resources &instance = Resources::getInstance();
	for (int y = 0; y < instance.map.size(); y++) {
		for (int x = 0; x < instance.map[y].size(); x++)
			delete instance.map[y][x];
		instance.map[y].clear();
	}
	instance.map.clear();
}

void Resources::draw(sf::RenderTarget & target){
	Resources &instance = Resources::getInstance();

	for (auto vector : instance.map)
		for (auto tile : vector)
			target.draw(*tile);
	for (auto pawn : instance.pawns)
		target.draw(*pawn);
}

void Resources::update(const float & deltaTime){
	Resources & instance = Resources::getInstance();

	for (auto pawn : instance.pawns)
		pawn->update(deltaTime);

	for (auto vectorTile : instance.map)
		for (auto tile : vectorTile)
			tile->update(deltaTime);
}

Pawn * Resources::addPawn(Pawn * pawn){
	if (pawn) 
		Resources::getInstance().pawns.push_back(pawn);

	return pawn;
}




