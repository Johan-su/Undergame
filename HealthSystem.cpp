#include "DebugMacros.h"
#include "HealthComponent.h"
#include "HealthSystem.h"
#include "ECS.h"


void HealthSystem::init()
{
	dead_entities = new std::vector<Entity>;
}

void HealthSystem::clean()
{
	delete dead_entities;
	dead_entities = nullptr;
}

void HealthSystem::update() //TODO: probably possible to make faster
{
	for(auto e : m_entities)
	{
		auto& health =  Game::coordinator->get_component<HealthComponent>(e);
#ifdef ECS_DEBUG
		SDL_assert(health.entity == e);
#endif
		if (health.health < 0.0f)
		{
			dead_entities->push_back(e);
		}
	}
	auto size = dead_entities->size();
	for (unsigned int i = 0; i < size; ++i)
	{
		Game::coordinator->destroy_entity(dead_entities->back());
		dead_entities->pop_back();
	}
}