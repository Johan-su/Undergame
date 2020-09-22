#include "TileMapGenerator.h"

TileMap* TileMapGenerator::create_map_random(const unsigned int& seed )
{
	auto tilemap = new TileMap();

	for (int i = 0; i < tilemap->grid.size(); ++i)
	{
		srand(seed + i);
		tilemap->grid[i] = rand() % 20; //TODO: change to actual amount of tile types

	}
	return tilemap;
}
TileMap* TileMapGenerator::create_map_perlin(const unsigned int& seed)
{
	return nullptr;
}
TileMap* TileMapGenerator::create_map_cellular(const unsigned int& seed)
{
	return nullptr;
}
TileMap* TileMapGenerator::create_map_simplex(const unsigned int& seed)
{
	return nullptr;
}
