#pragma once
#include "DebugMacros.h"
struct ColliderComponent
{
	int id;
	Uint32 other_entity;

#ifdef ECS_DEBUG
	Uint32 entity;
#endif
};