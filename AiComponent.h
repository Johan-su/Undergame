#pragma once
#include "DebugMacros.h"
enum AI_STATES
{
	RANDOM_WALKING,
	TRACK_LAST_KNOWN,
	TRACKING
};


struct AiComponent
{
	float detectionRadius;
	float lastX;
	float lastY;
	uint8_t state;
	std::array<uint32_t, > path_list;

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};