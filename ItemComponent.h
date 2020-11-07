#pragma once
#include <cstdint>
struct ItemComponent
{
	uint8_t itemtype;
	uint8_t amount;

#ifdef ECS_DEBUG
	uint32_t entity;
#endif
};