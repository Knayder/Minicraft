#ifndef RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Tile.h"
#include "Pawn.h"
#include "Tiles/GrassTile.h"

class Resources final {
public:
	typedef std::vector<std::vector<Tile *>> Map;
	typedef std::vector<Pawn *> Pawns;


	~Resources();
	Resources(const Resources &) = delete;
	void operator =(const Resources &) = delete;

	static void setDeltaTime(const float &deltaTime);

	static float getDeltaTime();

	static float getScale();
	
	static void setMap(const std::vector<std::vector<std::string>> &map, const float &scale);

	static void clearMap();


	static void draw(sf::RenderTarget &target);

	static void update();


	static Pawn * addPawn(Pawn *pawn);




private:
	Resources() {}
	Map map;
	Pawns pawns;

	float deltaTime;

	static Resources & getInstance();

	static Tile * newTile(Tile *tile, const sf::Vector2f & position, const float &scale);



};

#endif RESOURCES_H