#include "TileMapGenerator.h"

TileMap* TileMapGenerator::create_map_random(const unsigned long long& seed )
{
	auto tilemap = new TileMap();

	srand(seed);
	for (int i = 0; i < tilemap->grid.size(); ++i)
	{

		tilemap->grid[i];

	}

}
