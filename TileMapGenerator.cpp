#include <random>
#include <algorithm>
#include <cmath>
#include "vecf.h"
#include "TileMapGenerator.h"
#include "EntityCreator.h"
#include "ECS.h"


 uint32_t TileMapGenerator::seed;

void TileMapGenerator::init( uint32_t Seed)
{
	seed = Seed;
}


TileMap* TileMapGenerator::create_map_random()
{
	std::default_random_engine r;
	r.seed(seed);
	std::uniform_int_distribution< uint32_t> d(0, 15); //TODO: change to actual amount of tile types
	auto roll = std::bind(d, r);

	auto tilemap = new TileMap();

	for (int i = 0; i < tilemap->grid.size(); ++i)
	{
		tilemap->grid[i] = roll(); 
		//std::cout << "it " << i << std::endl;

	}
	create_boundary(tilemap);
	return tilemap;
}
TileMap* TileMapGenerator::create_map_value()
{
	auto tilemap = new TileMap();
	float scale = 0.08f;

	std::array<float, MAP_SIZE* MAP_SIZE>* v_values;
	v_values = new std::array<float, MAP_SIZE* MAP_SIZE>;

	for (int y = 0; y < MAP_SIZE; ++y)
	{
		for (int x = 0; x < MAP_SIZE; ++x)
		{
			auto v = TileMapGenerator::octaveValue((float)x * scale, (float)y * scale, 4, 0.5f);

			std::cout << "p " << v << " it " << x + y * MAP_SIZE << std::endl;

			(*v_values)[x + y * MAP_SIZE] = v;

			tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_AIR;
			if (v < 0.5f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_DIRT;
			}
			if (v > 0.55f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_STONE;
			}
			if (v > 0.68f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_EMERALD;
			}
			if (v > 0.7f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_DIAMOND;
			}
		}
	}
	auto maxr = std::distance(v_values->begin(), std::max_element(v_values->begin(), v_values->end()));
	auto minr = std::distance(v_values->begin(), std::min_element(v_values->begin(), v_values->end()));
	std::cout << "max element " << maxr << " = " << (*v_values)[maxr] << std::endl;
	std::cout << "min element " << minr << " = " << (*v_values)[minr] << std::endl;

	create_boundary(tilemap);
	delete v_values;

	return tilemap;
}
TileMap* TileMapGenerator::create_map_perlin()
{
	auto tilemap = new TileMap();
	float scale = 0.08f;

	std::array<float, MAP_SIZE* MAP_SIZE>* p_values;
	p_values = new std::array<float, MAP_SIZE* MAP_SIZE>;

	for (int y = 0; y < MAP_SIZE; ++y)
	{
		for (int x = 0; x < MAP_SIZE; ++x)
		{
			auto p = TileMapGenerator::octavePerlin((float)x * scale, (float)y * scale, 4, 0.5f);
			
			std::cout << "p " << p << " it " << x + y * MAP_SIZE << std::endl;

			(*p_values)[x + y * MAP_SIZE] = p;

			tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_AIR;
			if (p > 0.4f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_DIRT;
			}
			if (p > 0.55f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_STONE;
			}
			if (p > 0.68f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_EMERALD;
			}
			if (p > 0.7f)
			{
				tilemap->grid[x + y * MAP_SIZE] = TILE_TYPE_DIAMOND;
			}
		}
	}
	auto maxr = std::distance(p_values->begin(), std::max_element(p_values->begin(), p_values->end()));
	auto minr = std::distance(p_values->begin(), std::min_element(p_values->begin(), p_values->end()));
	std::cout << "max element " << maxr << " = " << (*p_values)[maxr] << std::endl;
	std::cout << "min element " << minr << " = " << (*p_values)[minr] << std::endl;

	create_boundary(tilemap);
	delete p_values;
	
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
	for ( uint32_t i = 0; i < MAP_SIZE; ++i)
	{
		tm->grid[i] = 16;
		tm->grid[i * MAP_SIZE] = 16;
		tm->grid[i + tm->grid.size() - MAP_SIZE] = 16;
		tm->grid[i * MAP_SIZE + MAP_SIZE - 1] = 16;
	}
}

float TileMapGenerator::octaveValue(float x, float y, uint16_t octaves, float persistance)
{
	float total = 0;
	float freq = 2;
	float amplitude = 64;
	float maxValue = 0;

	for (int i = 0; i < octaves; ++i)
	{
		total += value2d(x * freq, y * freq) * amplitude;
		maxValue += amplitude;

		amplitude *= persistance;
		freq *= 2;
	}

	return  total / maxValue;
}

float TileMapGenerator::value2d(float x, float y)
{
	float x0, x1, y0, y1;
	float r1, r2, r3, r4;
	x0 = floorf(x);
	x1 = x0 + 1;
	y0 = floorf(y);
	y1 = y0 + 1;


	r1 = create_gradient_value(x0, y0);
	r2 = create_gradient_value(x1, y0);
	r3 = create_gradient_value(x0, y1);
	r4 = create_gradient_value(x1, y1);


	float w1, w2;

	//w1 = x - x0;
	//w2 = y - y0;

	w1 = fade(x - x0);
	w2 = fade(y - y0);

	//std::cout << "w1 " << w1 << " w2 " << w2 << std::endl;

	auto l1 = lerp(r1, r2, w1);
	auto l2 = lerp(r3, r4, w1);

	auto l3 = lerp(l1, l2, w2);


	//std::cout << "x0 " << x0 << " x1 " << x1 << " y0 " << y0 << " y1 " << y1 << std::endl;

	//std::cout << "l1 " << l1 << " l2 " << l2 << " l3 " << l3 << std::endl;


	return l3;
}

float TileMapGenerator::create_gradient_value(float x, float y)
{
	uint32_t cseed = static_cast<uint32_t>(seed * (495222.4135123f + (cosf(x) + sinf(y))));
	srand(cseed); //TODO: check if random algorithm is truly random.

	float random = static_cast<float>(((double)rand() / (double)(RAND_MAX)));

	return random;
}

float TileMapGenerator::octavePerlin(float x, float y, uint16_t octaves, float persistance)
{
	float total = 0;
	float freq = 2;
	float amplitude = 64;
	float maxValue = 0;
	
	for (int i = 0; i < octaves; ++i)
	{
		total += perlin2d(x * freq, y * freq) * amplitude;
		maxValue += amplitude;

		amplitude *= persistance;
		freq *= 2;
	}

	return  (1 + sqrtf(2) * total / maxValue) / 2;
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

	g1 = create_gradient_vector(x0, y0);
	g2 = create_gradient_vector(x1, y0);
	g3 = create_gradient_vector(x0, y1);
	g4 = create_gradient_vector(x1, y1);


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


	//w1 = x - x0;
	//w2 = y - y0;
	w1 = fade(x - x0);
	w2 = fade(y - y0);

	//std::cout << "w1 " << w1 << " w2 " << w2 << std::endl;

	auto l1 = lerp(dot1, dot2, w1);
	auto l2 = lerp(dot3, dot4, w1);

	auto l3 = lerp(l1, l2, w2);


	//std::cout << "x0 " << x0 << " x1 " << x1 << " y0 " << y0 << " y1 " << y1 << std::endl;

	//std::cout << "l1 " << l1 << " l2 " << l2 << " l3 " << l3 << std::endl;


	return l3;
}


Vec2f TileMapGenerator::create_gradient_vector(float x, float y)
{
	uint32_t cseed = static_cast<uint32_t>(seed * (495222.4135123f + (cosf(x) + sinf(y))));
	srand(cseed); //TODO: check if random algorithm is truly random.

	float random = static_cast<float>(((double)rand() / (double)(RAND_MAX)) * 2 * M_PI);

	return Vec2f({ cosf(random), sinf(random) });
}

Vec2f TileMapGenerator::create_direction_vector(float x, float y, const Vec2f& vec)
{
	return Vec2f({ x - vec.x, y - vec.y });
}

float TileMapGenerator::lerp(float a, float b, float weight)
{
	return a + weight * (b - a);

}

float TileMapGenerator::fade(float a)
{
	return 6 * powf(a, 5) - 15 * powf(a, 4) + 10 * powf(a, 3);
}

float TileMapGenerator::dotProduct(const Vec2f& l, const Vec2f& r) 
{
	return l.x * r.x + l.y * r.y;
}