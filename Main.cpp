//#include <chrono>
#include <iostream>
#include <memory>
#include <SDL.h>
#include "ECS.h"
#include "Game.h"

static std::unique_ptr<Coordinator> g_coordinator;


int main(int argc, char* argv[])
{
	g_coordinator = std::make_unique<Coordinator>();


	std::vector<Entity> m_entities(MAX_ENTITIES);
	g_coordinator->init();

	g_coordinator->register_component<TransformComponent>();
	g_coordinator->register_component<RenderComponent>();
	g_coordinator->register_component<PlayerComponent>();
	g_coordinator->register_component<HealthComponent>();

	Entity e[5];
	e[0] = g_coordinator->create_entity();
	e[1] = g_coordinator->create_entity();
	e[2] = g_coordinator->create_entity();
	e[3] = g_coordinator->create_entity();
	e[4] = g_coordinator->create_entity();


	for (int i = 0; i < 5; ++i)
	{
	g_coordinator->add_component(e[i], TransformComponent());
	g_coordinator->add_component(e[i], RenderComponent());
	std::cout << (g_coordinator->m_entityManager->Get_signature(e[i])) << std::endl;
	}
	auto arr = g_coordinator->m_componentManager->get_component_array<TransformComponent>();




	std::cout << "\n";
	for (int i = 0; i < 5; ++i)
	{
		std::cout << (g_coordinator->m_entityManager->Get_signature(e[i])) << std::endl;
	}



	//std::cout << (m_coordinator->m_entityManager->Get_signature(e1)) << std::endl;


	std::cin.ignore();

	/*if (Game::init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 576, 0))
	{
		std::cout << "SDL_initalization failed" << std::endl;
		std::cin;
		return 1;
	}

	auto MS_PER_UPDATE = std::chrono::nanoseconds(16666666);


	auto previous = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds lag(0);
	while (Game::Running) {
		auto current = std::chrono::high_resolution_clock::now();
		auto elapsed = current - previous;
		previous = current;
		lag += elapsed;

		Game::events();

		while (lag >= MS_PER_UPDATE)
		{
			Game::update();
			lag -= MS_PER_UPDATE;
		}
		Game::render();
	}
	Game::clean();*/
	return 0;
}

