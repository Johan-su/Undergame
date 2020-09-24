#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <SDL.h>
#include "ECS.h"

enum EntityTypes
{
	ENTITY_TYPE_PLAYER,
	ENTITY_TYPE_NPC,
	ENTITY_TYPE_TILE,
};



class EntityCreator
{
public:
	static void init();

	static Entity create_entity(const size_t& type, const float& x, const float& y, unsigned long long data);

private:
	static std::vector<std::function<void(const Entity&, const float&, const float&, unsigned long long)>> func_pointers;

	static unsigned int create_player_id();

};
