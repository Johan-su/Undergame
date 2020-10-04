#pragma once
#include "ECS.h"
#include "TileMap.h"
class TileMapGenerator
{
public:

	static TileMap* create_map_random(Uint32 seed);

	static TileMap* create_map_perlin(Uint32 seed);

	static TileMap* create_map_cellular(Uint32 seed);

	static TileMap* create_map_simplex(Uint32 seed);

	static void entities_from_map(TileMap* tm);

	static void create_boundary(TileMap* tm);

private:

};