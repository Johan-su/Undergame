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
	void destroy_entity(const Entity& e)
	{
		m_entityManager->Destroy_entity(e);
		m_systemManager->remove_entity(e);
		m_componentManager->remove_entity(e);
	}
	template<typename T>
	void register_component()
	{
		m_componentManager->register_component_type<T>();
	}
	template<typename T>
	void add_component(const Entity& e, T component)
	{
		m_componentManager->add_component<T>(e, component);
		auto& sig = m_entityManager->Get_signature(e);
		sig.set(m_componentManager->get_component_pos<T>(), true);
		//m_entityManager->Set_signature(e, sig);
	}
	template<typename T>
	void remove_component(const Entity& e)
	{
		auto sig = m_entityManager->Get_signature(e);
		m_componentManager->destroy_component<T>(e);
		sig.set(m_componentManager->get_component_pos<T>(), false);
		m_entityManager->Set_signature(e, sig);
		m_systemManager->entity_changed_signature(e, sig);
	}
	template<typename T>
	T& get_component(const Entity& e)
	{
		return m_componentManager->get_component<T>(e);
	}
	template<typename T>
	uint8_t get_signature_pos()
	{
		return m_componentManager->get_component_pos<T>();
	}
	template<typename T>
	std::shared_ptr<T> register_system()
	{
		return m_systemManager->register_system<T>();
	}
	template<typename T>
	void set_signature(T system, std::bitset<MAX_COMPONENTS> signature)
	{
		m_systemManager->set_signature(system, signature);
	}




	std::unique_ptr<EntityManager> m_entityManager; // todo move to private
	std::unique_ptr<ComponentManager> m_componentManager; // todo move to private
	std::unique_ptr<SystemManager> m_systemManager; // todo move to private



private:
};