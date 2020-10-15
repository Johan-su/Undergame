#pragma once
#include "DebugMacros.h"
struct ProjectileComponent
{
	float damage;

#ifdef ECS_DEBUG
	Uint32 entity;
#endif
};