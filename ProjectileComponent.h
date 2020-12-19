#pragma once
#include "DebugMacros.h"
struct ProjectileComponent
{
	float damage;
	uint8_t Playerid;

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};