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

void Resources::setDeltaTime(const float & deltaTime)
{
	Resources::getInstance().deltaTime = deltaTime;
}

float Resources::getDeltaTime()
{
	return Resources::getInstance().deltaTime;
}

void Resources::setScale(const float & scale)
{
	Resources::getInstance().scale = scale;
}

float Resources::getScale()
{
	return Resources::getInstance().scale;
}

void Resources::setMap(const std::vector<std::vector<std::string>>& newMap)
{
	Resources &instance = Resources::getInstance();
	Resources::clearMap();
	float scale = Resources::getScale();
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

Tile * Resources::getTile(sf::Vector2i position)
{
	Resources & instance = Resources::getInstance();
	if(position.y < instance.map.size() && position.x < instance.map[position.y].size())
		return instance.map[position.y][position.x];
	else
		return nullptr;
}

void Resources::draw(sf::RenderTarget & target){
	Resources &instance = Resources::getInstance();

	for (auto vector : instance.map)
		for (auto tile : vector)
			target.draw(*tile);
	for (auto pawn : instance.pawns)
		target.draw(*pawn);
}

void Resources::update(){
	Resources & instance = Resources::getInstance();

	for (auto pawn : instance.pawns)
		pawn->update();

	for (auto vectorTile : instance.map)
		for (auto tile : vectorTile)
			tile->update();
}

Pawn * Resources::addPawn(Pawn * pawn){
	if (pawn) 
		Resources::getInstance().pawns.push_back(pawn);

	return pawn;
}




