#include <chrono>
#include <iostream>
#include <memory>
#include <SDL.h>
#include "EntityCreator.h"
#include "Texture.h"
#include "ECS.h"
#include "Game.h"





int main(int argc, char* argv[])
{
	std::vector<Entity> m_entities(MAX_ENTITIES);

	if (Game::init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 576, 0))
	{
		std::cout << "Game_initalization failed" << std::endl;

		return 1;
	}
	Texture::init();
	EntityCreator::init();


	EntityCreator::create_entity(1337, 1337, ENTITY_TYPE_PLAYER);













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
	Game::clean();
	return 0;
}

