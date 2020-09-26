#pragma once
#include "ECS.h"
#include "TileMap.h"
class TileMapGenerator
{
public:

	static TileMap* create_map_random(const unsigned int& seed);

	static TileMap* create_map_perlin(const unsigned int& seed);

	static TileMap* create_map_cellular(const unsigned int& seed);

	static TileMap* create_map_simplex(const unsigned int& seed);

	static void entities_from_map(TileMap* tm);

	static void create_boundary(TileMap* tm);

private:

};