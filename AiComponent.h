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
	uint8_t state;
};