#pragma once
#include <memory>
#include "ECS.h"

class SystemManager
{
public:
	template<typename T>
	System* register_system()
	{
		std::string systemName = typeid(T).name();
		auto system = new T;
		m_systemMap.insert(systemName, system);
		return system;

	}
	template<typename T>
	void set_signature(T system, std::bitset<MAX_COMPONENTS> signature)
	{
		std::string systemName = typeid(T).name();

		m_signatures[systemName] = signature;
	}
	void remove_entity(const Entity& e)
	{
		for (auto const& pair : m_systemMap)
		{
			auto const& system = pair.second;
			system->m_entities.erase(e);
		}
	}
	void entity_changed_signature(const Entity& e, std::bitset<MAX_COMPONENTS> e_signature)
	{
		for (auto const& pair : m_systemMap)
		{
			auto const& type = pair.first;
			auto const& system = pair.second;
			auto& signature = m_signatures[type];
			auto const& comparisionSignature = signature & e_signature;

			if (comparisionSignature == signature)
			{
				system->m_entities.insert(e);
			}
			else
			{
				system->m_entities.erase(e);
			}
		}
	}
private:

	std::unordered_map<std::string, std::bitset<MAX_COMPONENTS>> m_signatures;

	std::unordered_map<std::string, System*> m_systemMap;
};
