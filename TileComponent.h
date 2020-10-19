#pragma once
#include <cstdint>
#include "DebugMacros.h"
#include "vecf.h"
struct TileComponent
{
	uint8_t type;

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};