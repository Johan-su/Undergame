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
	ENTITY_TYPE_MOLE,
	ENTITY_TYPE_BULLET
};



class EntityCreator
{
public:
	static void init();

	static void create_entity(const size_t& type, const float& x, const float& y, void* data);

private:
	static std::vector<std::function<void(const Entity&, const float&, const float&, void* )>> func_pointers;

	static unsigned int create_player_id();

};
