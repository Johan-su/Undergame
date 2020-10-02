#include <random>
#include <cmath>
#include "TileMapGenerator.h"
#include "EntityCreator.h"
#include "ECS.h"


TileMap* TileMapGenerator::create_map_random(const unsigned int& seed)
{
	std::default_random_engine r;
	r.seed(seed);
	std::uniform_int_distribution<unsigned int> d(0, 15); //TODO: change to actual amount of tile types
	auto roll = std::bind(d, r);

	auto tilemap = new TileMap();

	for (int i = 0; i < tilemap->grid.size(); ++i)
	{
		tilemap->grid[i] = roll(); 

	}
	create_boundary(tilemap);
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
void TileMapGenerator::entities_from_map(TileMap* tm) 
{
	for (unsigned int i = 0; i < tm->grid.size(); ++i)
	{
		int x = TILE_SIZE * (i % (MAP_SIZE));
		int y = TILE_SIZE * (i / (MAP_SIZE));
		auto& type = tm->grid[i];
		//std::cout << i << "\n";
		if (type == 0)
		{

		Game::tileEntities[i] = type;
		continue;
		}
		EntityCreator::create_entity(ENTITY_TYPE_TILE, static_cast<float>(x), static_cast<float>(y), &type);
		Game::tileEntities[i] = type;
	}
}
void TileMapGenerator::create_boundary(TileMap* tm)
{
	for (unsigned int i = 0; i < MAP_SIZE; ++i)
	{
		tm->grid[i] = 16;
		tm->grid[i * MAP_SIZE] = 16;
		tm->grid[i + tm->grid.size() - MAP_SIZE] = 16;
		tm->grid[i * MAP_SIZE + MAP_SIZE - 1] = 16;
	}
}