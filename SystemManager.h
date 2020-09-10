#pragma once
#include "ECS.h"

class SystemManager
{
public:
	template<typename T>
	T* register_system()
	{
		std::string systemName = typeid(T).name();

	}
	template<typename T>
	void set_signature(T system, std::bitset<MAX_COMPONENTS> signature)
	{
		std::string systemName = typeid(T).name();

		m_signatures[systemName] = signature;
	}
	void remove_entity(const Entity& e)
	{
		for (auto const& pair : m_systemArray)
		{
			auto const& system = pair.second;
			system->m_entities.erase(e.id);
		}
	}
	void entity_changed_signature(const Entity& e, std::bitset<MAX_COMPONENTS> e_signature)
	{
		for (auto const& pair : m_systemArray)
		{
			auto const& type = pair.first;
			auto const& system = pair.second;
			auto& signature = m_signatures[type];
			auto const& comparisionSignature = signature & e_signature;

			if (comparisionSignature == signature)
			{
				system->m_entities.insert(e.id);
			}
			else
			{
				system->m_entities.erase(e.id);
			}
		}
	}
private:

	std::unordered_map<std::string, std::bitset<MAX_COMPONENTS>> m_signatures;

	std::unordered_map<std::string, System*> m_systemArray;
};
