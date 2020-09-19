#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <SDL.h>
#include "ECS.h"

enum EntityTypes
{
	ENTITY_TYPE_PLAYER
};



class EntityCreator
{
public:
	static void init();

	static Entity create_entity(const float& x, const float& y, const size_t& type);

private:
	static std::vector<std::function<void(const float&, const float&, const Entity&)>> func_pointers;

	static unsigned int create_player_id();

};
