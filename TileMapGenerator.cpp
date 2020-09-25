#include "TileMapGenerator.h"
#include "EntityCreator.h"
#include "ECS.h"


TileMap* TileMapGenerator::create_map_random(const unsigned int& seed )
{

	auto tilemap = new TileMap();

	for (int i = 0; i < tilemap->grid.size(); ++i)
	{
		srand(seed + i);
		tilemap->grid[i] = rand() % 20; //TODO: change to actual amount of tile types
		//std::cout << "grid type " << static_cast<int>(tilemap->grid[i]) << "\n";

	}
	return tilemap;
}
TileMap* TileMapGenerator::create_map_perlin(const unsigned int& seed)
{
	return nullptr;
}
TileMap* TileMapGenerator::create_map_cellular(const unsigned int& seed) // maybe not worth doing cellular automata generation
{
	return nullptr;
}
TileMap* TileMapGenerator::create_map_simplex(const unsigned int& seed)
{
	return nullptr;
}
void TileMapGenerator::entities_from_map(TileMap* tm) //TODO: maybe change to multithreading
{
	for (unsigned int i = 0; i < tm->grid.size(); ++i)
	{
		int x = TILE_SIZE * (i % (MAP_SIZE));
		int y = TILE_SIZE * (i / (MAP_SIZE));
		const auto& type = tm->grid[i];
		//std::cout << i << "\n";
		Game::entities->push_back(EntityCreator::create_entity(ENTITY_TYPE_TILE, static_cast<float>(x), static_cast<float>(y), type));
	}
}