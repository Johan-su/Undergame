#pragma once
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
};