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
	float digSpeed;
	uint8_t state;

#ifdef ECS_DEBUG
	Uint32 entity;
#endif
};