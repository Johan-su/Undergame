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


	static float perlin2d(float x, float y, Uint32 seed); // TODO: move to private
private:

	static void create_boundary(TileMap* tm);


	static Vec2f create_gradient_vector(float length, Uint32 seed);

	static Vec2f create_direction_vector(float x, float y, const Vec2f& vec);

	static float lerp(float x, float y, float weight);

	static float dotProduct(const Vec2f& l, const Vec2f& r);
};