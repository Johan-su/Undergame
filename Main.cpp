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

//#define NLOOP




void Create_entities()
{

	auto tm = TileMapGenerator::create_map_random(-1);
	TileMapGenerator::entities_from_map(tm);
	float x, y;
	for (unsigned int i = 0; i < MAP_SIZE * MAP_SIZE; ++i)
	{
		if (Game::tileEntities[i] == 0)
		{
			x = static_cast<float>(TILE_SIZE * (i % MAP_SIZE) + TILE_SIZE / 2);
			y = static_cast<float>(TILE_SIZE * (i / MAP_SIZE) + TILE_SIZE / 2);
			break;
		}
	}
	EntityCreator::create_entity(ENTITY_TYPE_PLAYER, x, y, nullptr);
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
#ifndef NLOOP
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
#else
	while (Game::Running)
	{
		Game::events();
		Game::update();
		Game::render();
	}
#endif
	//t1.join();
	Game::clean();
	return 0;
}

