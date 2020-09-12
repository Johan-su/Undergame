#pragma once
#include <memory>
#include "ECS.h"

class Coordinator
{
public:
	void init()
	{

		m_entityManager = std::make_unique<EntityManager>();
		m_componentManager = std::make_unique<ComponentManager>(); 
		m_systemManager = std::make_unique<SystemManager>();
	}
	Entity create_entity()
	{
		return m_entityManager->Create_entity();
	}
	void destroy_entity(Entity& e)
	{
		m_entityManager->Destroy_entity(e);
	}
	template<typename T>
	void register_component()
	{
		m_componentManager->register_component_type(T);
	}
	template<typename T>
	void add_component(Entity e, T component)
	{
		m_componentManager->add_component<T>(e);
	}
private:
	EntityManager* enttest;
	std::unique_ptr<EntityManager> m_entityManager;
	std::unique_ptr<ComponentManager> m_componentManager;
	std::unique_ptr<SystemManager> m_systemManager;
};