#include <random>
#include <cmath>
#include "vecf.h"
#include "TileMapGenerator.h"
#include "EntityCreator.h"
#include "ECS.h"


TileMap* TileMapGenerator::create_map_random(Uint32 seed)
{
	std::default_random_engine r;
	r.seed(seed);
	std::uniform_int_distribution<Uint32> d(0, 15); //TODO: change to actual amount of tile types
	auto roll = std::bind(d, r);

	auto tilemap = new TileMap();

	for (int i = 0; i < tilemap->grid.size(); ++i)
	{
		tilemap->grid[i] = roll(); 

	}
	create_boundary(tilemap);
	return tilemap;
}
TileMap* TileMapGenerator::create_map_perlin(Uint32 seed)
{
	auto tilemap = new TileMap();


	return nullptr;
}
TileMap* TileMapGenerator::create_map_cellular(Uint32 seed) // maybe not worth doing cellular automata generation
{
	return nullptr;
}
TileMap* TileMapGenerator::create_map_simplex(Uint32 seed)
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
	for (Uint32 i = 0; i < MAP_SIZE; ++i)
	{
		tm->grid[i] = 16;
		tm->grid[i * MAP_SIZE] = 16;
		tm->grid[i + tm->grid.size() - MAP_SIZE] = 16;
		tm->grid[i * MAP_SIZE + MAP_SIZE - 1] = 16;
	}
}

float TileMapGenerator::perlin2d(float x, float y, Uint32 seed)
{
	float x0, x1, y0, y1;
	float dot1, dot2, dot3, dot4;
	x0 = TILE_SIZE * floorf(x / TILE_SIZE);
	x1 = x0 + TILE_SIZE;
	y0 = TILE_SIZE * floorf(fmod(y, TILE_SIZE));
	y1 = y0 + TILE_SIZE;

	Vec2f g1, g2, g3, g4, d1, d2, d3, d4;

	g1 = create_gradient_vector(TILE_SIZE, seed);
	g2 = create_gradient_vector(TILE_SIZE, seed);
	g3 = create_gradient_vector(TILE_SIZE, seed);
	g4 = create_gradient_vector(TILE_SIZE, seed);

	d1 = create_direction_vector(x, y, g1);
	d2 = create_direction_vector(x, y, g2);
	d3 = create_direction_vector(x, y, g3);
	d4 = create_direction_vector(x, y, g4);

	dot1 = dotProduct(g1, d1);
	dot2 = dotProduct(g2, d2);
	dot3 = dotProduct(g3, d3);
	dot4 = dotProduct(g4, d4);

	std::cout << "x0 " << x0 << " x1 " << x1 << " y0 " << y0 << " y1 " << y1 << std::endl;





	return 0.0f;
}

Vec2f TileMapGenerator::create_gradient_vector(float length, Uint32 seed)
{
	std::default_random_engine r;
	r.seed(seed);
	std::uniform_real_distribution<float> d(0, static_cast<float>(M_PI));
	auto roll = std::bind(d, r);

	return Vec2f({ cosf(roll() * length), sinf(roll()) * length });
}

Vec2f TileMapGenerator::create_direction_vector(float x, float y, const Vec2f& vec)
{
	return Vec2f({x-vec.x, y-vec.y});
}

float TileMapGenerator::lerp(float x, float y, float weight)
{

}

float TileMapGenerator::dotProduct(const Vec2f& l, const Vec2f& r)
{
	return l.x * r.x + l.y * r.y;
}