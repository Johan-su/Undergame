#pragma once
#include <array>
#include <bitset>
#include <queue>
#include "Entity.h"
#include "ECS.h"


class EntityManager
{
public:
	EntityManager()
	: m_entityCount(0)
	{
		for (uint32_t id = 0; id < MAX_ENTITIES; ++id)
		{
			m_AvailableIDs.push(id);
		}
	}

	Entity Create_entity()
	{
		if (m_entityCount > MAX_ENTITIES)
		{
			throw "too many entities";
		}

		Entity e;
		e.id = m_AvailableIDs.front();
		m_AvailableIDs.pop();
		++m_entityCount;
		return e;
	}

	void Destroy_entity(const Entity& e)
	{
		m_signatures[e.id].reset();

		m_AvailableIDs.push(e.id);
		--m_entityCount;
	}

	void Set_signature(const Entity& e, std::bitset<MAX_COMPONENTS> signature)
	{
		m_signatures[e.id] = signature;
	}

	std::bitset<MAX_COMPONENTS> Get_signature(const Entity& e)
	{
		return m_signatures[e.id];
	}

private:
	std::queue<uint32_t> m_AvailableIDs;

	std::array<std::bitset<MAX_COMPONENTS>, 50000> m_signatures;

	uint32_t m_entityCount;
};