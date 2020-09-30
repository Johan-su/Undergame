#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <SDL.h>
#include "EntityCreator.h"
#include "Texture.h"
#include "ECS.h"
#include "Game.h"
#include "Tilemap.h"
#include "TileMapGenerator.h"



void Create_entities()
{

	auto tm = TileMapGenerator::create_map_random(52321232340);
	TileMapGenerator::entities_from_map(tm);
	float x, y;
	for (unsigned int i = 0; i < MAP_SIZE * MAP_SIZE; ++i)
	{
		if (Game::tileEntities[i] == 0)
		{
			x = TILE_SIZE * (i % MAP_SIZE) + TILE_SIZE / 2;
			y = TILE_SIZE * (i / MAP_SIZE) + TILE_SIZE / 2;
			break;
		}
	}
	Game::entities->push_back(EntityCreator::create_entity(ENTITY_TYPE_PLAYER, x, y, 0));


}

int main(int argc, char* argv[])
{
	auto before = std::chrono::high_resolution_clock::now();
	if (Game::init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0))
	{
		std::cout << "Game_initalization failed" << std::endl;

		return 1;
	}

	EntityCreator::init();
	//std::thread t1(Create_entities);
	Create_entities();
	auto after = std::chrono::high_resolution_clock::now();

	auto dt = after - before;

	std::cout << "ns: " << dt.count() << " ms: " << dt.count() / 1000000.0f << " s: " << dt.count() / 1000000000.0f << std::endl;

	auto NS_PER_UPDATE = std::chrono::nanoseconds(16666666);
	auto previous = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds lag(0);
	while (Game::Running) {
		auto current = std::chrono::high_resolution_clock::now();
		auto elapsed = current - previous;
		previous = current;
		lag += elapsed;


		while (lag >= NS_PER_UPDATE)
		{
			Game::events();
			Game::update();
			lag -= NS_PER_UPDATE;
		}
		Game::render();
	}
	//t1.join();
	Game::clean();
	return 0;
}

