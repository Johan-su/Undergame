#pragma once
#include "ECS.h"
#include "TileMap.h"
class TileMapGenerator
{
public:

	static void init(Uint32 Seed);

	static TileMap* create_map_random();

	static TileMap* create_map_perlin();

	static TileMap* create_map_simplex();

	static void entities_from_map(TileMap* tm);

	static float perlin2d(float x, float y); // TODO: move to private

private:

	static void create_boundary(TileMap* tm);


	static Vec2f create_gradient_vector(float x, float y, float length);

	static Vec2f create_direction_vector(float x, float y, const Vec2f& vec);

	static float lerp(float x, float y, float weight);

	static float dotProduct(const Vec2f& l, const Vec2f& r);

	static Uint32 seed;

};