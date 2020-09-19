#include <chrono>
#include <iostream>
#include <memory>
#include <SDL.h>
#include "EntityCreator.h"
#include "Texture.h"
#include "Main.h"
#include "ECS.h"
#include "Game.h"

static std::shared_ptr<System> renderSystem;


void ECS_init()
{
	Game::coordinator->init();
	Game::coordinator->test();
	components_init();
	systems_init();



	
}

void components_init()
{
	Game::coordinator->register_component<TransformComponent>();
	Game::coordinator->register_component<RenderComponent>();
	Game::coordinator->register_component<PlayerComponent>();
	Game::coordinator->register_component<HealthComponent>();
}

void systems_init()
{
	renderSystem = Game::coordinator->register_system<RenderSystem>();
	std::bitset<MAX_COMPONENTS> sig;
	sig.set(Game::coordinator->get_signature_pos<TransformComponent>());
	sig.set(Game::coordinator->get_signature_pos<RenderComponent>());
	Game::coordinator->set_signature(renderSystem, sig);
}

int main(int argc, char* argv[])
{
	std::vector<Entity> m_entities(MAX_ENTITIES);

	if (Game::init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 576, 0))
	{
		std::cout << "Game_initalization failed" << std::endl;

		return 1;
	}
	Texture::init();
	ECS_init();

	EntityCreator::init();
	EntityCreator::create_entity(1337, 1337, ENTITY_TYPE_PLAYER);
















	for (int i = 0; i < 100; ++i)
	{
		m_entities.push_back(Game::coordinator->create_entity());
		auto tc = TransformComponent();
		auto rc = RenderComponent();
		Game::coordinator->add_component<TransformComponent>(m_entities.back(), tc);
		Game::coordinator->add_component<RenderComponent>(m_entities.back(), rc);


	}




	auto NS_PER_UPDATE = std::chrono::nanoseconds(16666666);
	auto previous = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds lag(0);
	while (Game::Running) {
		auto current = std::chrono::high_resolution_clock::now();
		auto elapsed = current - previous;
		previous = current;
		lag += elapsed;

		Game::events();

		while (lag >= NS_PER_UPDATE)
		{
			Game::update();
			lag -= NS_PER_UPDATE;
		}
		Game::render();
	}
	Game::clean();
	return 0;
}

