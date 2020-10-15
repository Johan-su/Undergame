#include <random>
#include <cmath>
#include "vecf.h"
#include "TileMapGenerator.h"
#include "EntityCreator.h"
#include "ECS.h"


Uint32 TileMapGenerator::seed;

void TileMapGenerator::init(Uint32 Seed)
{
	seed = Seed;
}


TileMap* TileMapGenerator::create_map_random()
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
TileMap* TileMapGenerator::create_map_perlin()
{
	auto tilemap = new TileMap();


	for (int y = 0; y < MAP_SIZE; ++y)
	{
		for (int x = 0; x < MAP_SIZE; ++x)
		{
			auto p = 4 * TileMapGenerator::perlin2d(0.5f + (float)x * 0.010f, 0.5f + (float)y * 0.010f);
			std::cout << "p " << p << " it " << x + y * MAP_SIZE << std::endl;
			if (p > 0.3f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_STONE;
			}
			else
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_AIR;
			}

		}
	}
	create_boundary(tilemap);
	return tilemap;
}
TileMap* TileMapGenerator::create_map_simplex()
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

float TileMapGenerator::perlin2d(float x, float y)
{
	float x0, x1, y0, y1;
	float dot1, dot2, dot3, dot4;
	x0 = floorf(x);
	x1 = x0 + 1;
	y0 = floorf(y);
	y1 = y0 + 1;

	Vec2f g1, g2, g3, g4, d1, d2, d3, d4;

	g1 = create_gradient_vector(x0, y0, 1);
	g2 = create_gradient_vector(x1, y0, 1);
	g3 = create_gradient_vector(x0, y1, 1);
	g4 = create_gradient_vector(x1, y1, 1);


	//std::cout << "g1x " << g1.x << " g1y " << g1.y << " g2x " << g2.x << " g2y " << g2.y << " g3x " << g3.x << " g3y " << g3.y << " g4x " << g4.x << " g4y " << g4.y << std::endl;




	d1 = create_direction_vector(x, y, Vec2f({ x0, y0 }));
	d2 = create_direction_vector(x, y, Vec2f({ x1, y0 }));
	d3 = create_direction_vector(x, y, Vec2f({ x0, y1 })); 
	d4 = create_direction_vector(x, y, Vec2f({ x1, y1 }));


	//std::cout << "d1x " << d1.x << " d1y " << d1.y << " d2x " << d2.x << " d2y " << d2.y << " d3x " << d3.x << " d3y " << d3.y << " d4x " << d4.x << " d4y " << d4.y << std::endl;


	dot1 = dotProduct(g1, d1);
	dot2 = dotProduct(g2, d2);
	dot3 = dotProduct(g3, d3);
	dot4 = dotProduct(g4, d4);

	//std::cout << "dot1 " << dot1 << " dot2 " << dot2 << " dot3 " << dot3 << " dot4 " << dot4 << std::endl;
 
	float w1, w2;

	w1 = x - x0;
	w2 = y - y0;

	//std::cout << "w1 " << w1 << " w2 " << w2 << std::endl;

	auto l1 = lerp(dot1, dot2, w1);
	auto l2 = lerp(dot3, dot4, w1);

	auto l3 = lerp(l1, l2, w2);


	//std::cout << "x0 " << x0 << " x1 " << x1 << " y0 " << y0 << " y1 " << y1 << std::endl;

	//std::cout << "l1 " << l1 << " l2 " << l2 << " l3 " << l3 << std::endl;


	return l3;
}

Vec2f TileMapGenerator::create_gradient_vector(float x, float y, float length)
{
	srand(static_cast<Uint32>(seed * x * y + seed * (1 + x + y))); //TODO: check if random algorithm is truly random.

	float random = static_cast<float>(((double)rand() / (double)(RAND_MAX)) * 2 * M_PI);

	//std::cout << "random " << random << std::endl;

	return Vec2f({ cosf(random) * length, sinf(random) * length });
}

Vec2f TileMapGenerator::create_direction_vector(float x, float y, const Vec2f& vec)
{
	return Vec2f({ x - vec.x, y - vec.y });
}

float TileMapGenerator::lerp(float a, float b, float weight)
{
	return a + weight * (b - a);

}

float TileMapGenerator::dotProduct(const Vec2f& l, const Vec2f& r)
{
	return l.x * r.x + l.y * r.y;
}