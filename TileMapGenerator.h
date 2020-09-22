#pragma once
#include "ECS.h"
#include "TileMap.h"
class TileMapGenerator
{
public:

	static TileMap* create_map_random(const unsigned long long& seed);

	static TileMap* create_map_perlin(const unsigned long long& seed);

	static TileMap* create_map_cellular(const unsigned long long& seed);

	static TileMap* create_map_simplex(const unsigned long long& seed);

private:


};