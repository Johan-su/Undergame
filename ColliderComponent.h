#pragma once
#include "DebugMacros.h"
struct ColliderComponent
{
	int id;
	 uint32_t other_entity;

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};