#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <SDL.h>
#include "DebugMacros.h"
#include "EntityCreator.h"
#include "Texture.h"
#include "ECS.h"
#include "Game.h"
#include "Tilemap.h"
#include "TileMapGenerator.h"

//#define NLOOP
//#define FPSLOOP






void Create_entities()
{
	//auto before = std::chrono::high_resolution_clock::now(); // för tidsmätning av noise funktionerna

	//auto tm = TileMapGenerator::create_map_random();
	//auto tm = TileMapGenerator::create_map_value();
	auto tm = TileMapGenerator::create_map_perlin();
	//auto tm = TileMapGenerator::create_map_simplex();

	/*auto after = std::chrono::high_resolution_clock::now();

	auto dt = after - before;

	std::cout << "ns: " << dt.count() << " ms: " << dt.count() / 1000000.0f << " s: " << dt.count() / 1000000000.0f << std::endl;
	std::cin.ignore();*/ // för tidsmätning av noise funktionerna

	TileMapGenerator::entities_from_map(tm);
	float x, y;
	auto& health = Game::coordinator->get_component<HealthComponent>(2 * MAP_SIZE);

	for (unsigned int i = 0; i < MAP_SIZE * MAP_SIZE; ++i)
	{
		if (Game::tileEntities[i] == 0)
		{
			x = (float)(TILE_SIZE * (i % MAP_SIZE) + TILE_SIZE / 2);
			y = (float)(TILE_SIZE * (i / MAP_SIZE) + TILE_SIZE / 2);
			break;
		}
	}
	EntityCreator::create_entity(ENTITY_TYPE_PLAYER, x, y, 0);
	EntityCreator::create_entity(ENTITY_TYPE_MOLE, x, y, 0);
	delete tm;
}

int main(int argc, char* argv[])
{
	auto before = std::chrono::high_resolution_clock::now();
#ifdef ECS_DEBUG
	std::cout << "ECS_DEBUG ENABLED" << std::endl;
#endif
	DP("PRINT_DEBUG ENABLED");
	std::cout << Game::seed << std::endl;
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

#ifdef FPSLOOP
	uint32_t fps = 0;
	uint16_t count = 0;
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
			if (count >= 60)
			{
				std::cout << "FPS: " << fps << std::endl;
				count = 0;
				fps = 0;
			}
			++count;
		}
		Game::render();
		++fps;
	}
#else
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
#endif
/*#ifndef NLOOP
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
#endif*/
	//t1.join();
	Game::clean();
	return 0;
}

