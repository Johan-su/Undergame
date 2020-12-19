#pragma once
#include <cstdint>
#include "DebugMacros.h"

struct PlayerComponent
{
	uint32_t bullets;
	uint32_t bombs;
	uint32_t kills;

	uint8_t bulletWeaponsType; // bullet weapons
	uint8_t explosiveWeaponsType; // explosive weapons

	uint8_t playerId;

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};