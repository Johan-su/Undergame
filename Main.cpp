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
	auto before = std::chrono::high_resolution_clock::now();


	auto tm = TileMapGenerator::create_map_random(185819056);
	TileMapGenerator::entities_from_map(tm);
	delete tm;
	Game::entities->push_back(EntityCreator::create_entity(ENTITY_TYPE_PLAYER, 0, 0, 0));


	auto after = std::chrono::high_resolution_clock::now();
	auto dt = after - before;
	std::cout << "ns: " << dt.count() << " ms: " << dt.count() / 1000000.0f << " s: " << dt.count() / 1000000000.0f << std::endl;
}

int main(int argc, char* argv[])
{
	if (Game::init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0))
	{
		std::cout << "Game_initalization failed" << std::endl;

		return 1;
	}

	EntityCreator::init();
	std::thread t1(Create_entities);
	//Create_entities();
	


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
	t1.join();
	Game::clean();
	return 0;
}

