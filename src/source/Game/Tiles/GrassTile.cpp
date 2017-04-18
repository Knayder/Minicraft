#include "..\..\..\headers\Game\Tiles\GrassTile.h"
#include "..\..\..\headers\Game\Tools\Shovel.h"

GrassTile::GrassTile(const std::string &name) :
	Tile(name)
{

}

void GrassTile::use(Tool * tool, Pawn *pawn){
	if (dynamic_cast<Shovel*>(tool) != nullptr) {
		setTexture("shovel");
	}
	
}
