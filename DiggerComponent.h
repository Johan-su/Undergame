#pragma once
#include <cstdint>
#include <cstdlib>
struct DiggerComponent
{
	uint8_t drillLVL;
	uint8_t drillStates;

#ifdef ECS_DEBUG
	uint32_t entity;
#endif
};