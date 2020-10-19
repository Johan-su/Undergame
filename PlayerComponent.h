#pragma once
#include <cstdint>
#include "DebugMacros.h"
struct PlayerComponent
{
	 uint32_t bullets;
	 uint32_t bombs;

	Uint8 bulletWeaponsType; // bullet weapons
	Uint8 explosiveWeaponsType; // explosive weapons


#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};