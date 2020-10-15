#pragma once
#include <cstdint>
#include "DebugMacros.h"
struct PlayerComponent
{
	unsigned int id;
	unsigned int drillLVL;
	unsigned int bulletWeaponsType; // bullet weapons
	unsigned int explosiveWeaponsType; // explosive weapons
	unsigned int bullets;
	unsigned int bombs;


#ifdef ECS_DEBUG
	Uint32 entity;
#endif
};