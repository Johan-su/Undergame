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
	float visualRadius;
	float lastX;
	float lastY;
	uint8_t state;

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};