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

void HealthSystem::update()
{
	for(auto e : m_entities)
	{
		auto& health =  Game::coordinator->get_component<HealthComponent>(e);

		if (health.health <= 0)
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