#include "..\..\..\headers\Game\Tiles\GrassTile.h"
#include "..\..\..\headers\Game\Tools\Shovel.h"

GrassTile::GrassTile(const int &index) :
	Tile(index)
{

}

void GrassTile::use(Tool * tool, Pawn *pawn){
	if (dynamic_cast<Shovel*>(tool) != nullptr) {
		setTexture(51);
	}
	
}
