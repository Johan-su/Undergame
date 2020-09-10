#pragma once
#include <array>
#include <bitset>
#include <queue>
#include "Entity.h"
#include "ECS.h"


class EntityManager
{
public:
	EntityManager();

	Entity Create_entity();

	void Destroy_entity(const Entity& e);

	void Set_signature(const Entity& e, std::bitset<MAX_COMPONENTS> signature);

	std::bitset<MAX_COMPONENTS> Get_signature(const Entity& e);

private:
	std::queue<uint32_t> m_AvailableIDs;

	std::array<std::bitset<MAX_COMPONENTS>, 50000> m_signatures;

	uint32_t m_entityCount;
};