#include <random>
#include <cmath>
#include "TileMapGenerator.h"
#include "EntityCreator.h"
#include "ECS.h"


TileMap* TileMapGenerator::create_map_random(const unsigned int& seed )
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
void TileMapGenerator::entities_from_map(TileMap* tm) //TODO: maybe change to multithreading
{
	for (unsigned int i = 1; i < tm->grid.size(); ++i)
	{
		int x = TILE_SIZE * (i % (MAP_SIZE));
		int y = TILE_SIZE * (i / (MAP_SIZE));
		const auto& type = tm->grid[i];
		//std::cout << i << "\n";
		Game::entities->push_back(EntityCreator::create_entity(ENTITY_TYPE_TILE, static_cast<float>(x), static_cast<float>(y), type));
	}
}
void TileMapGenerator::create_boundary(TileMap* tm)
{
	unsigned int rowsize = static_cast<unsigned int>(sqrt(tm->grid.size()));

	for (unsigned int i = 0; i < rowsize; ++i)
	{
		tm->grid[i] = 16;
		tm->grid[i * rowsize] = 16;
		tm->grid[i + tm->grid.size() - rowsize] = 16;
		tm->grid[i * rowsize + rowsize - 1] = 16;
	}
}