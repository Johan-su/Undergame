#pragma once
#include <vector>
#include "DebugMacros.h"

enum AI_STATES
{
	AI_STATE_RANDOM_WALKING,
	AI_STATE_TRACK_LAST_KNOWN,
	AI_STATE_TRACKING
};


struct AiComponent
{
	float detectionRadius;
	float lastX;
	float lastY;
	uint8_t state;
	std::vector<uint32_t> path_list;

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};