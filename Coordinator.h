#pragma once
#include <memory>
#include "ECS.h"

class Coordinator
{
public:
	void init()
	{
		m_entityManager = std::make_unique<EntityManager>();
		m_componentManager = std::make_unique<ComponentManager>(); //TODO: fix not working
		m_systemManager = std::make_unique<SystemManager>();
	}
	Entity create_entity()
	{

	}
	void destroy_entity(Entity& e)
	{

	}

private:
	std::unique_ptr<EntityManager> m_entityManager;
	std::unique_ptr<ComponentManager> m_componentManager;
	std::unique_ptr<SystemManager> m_systemManager;
};