#pragma once
enum AI_STATES
{
	RANDOM_WALKING,
	TRACK_LAST_KNOWN,
	TRACKING
};


struct AiComponent
{
	uint8_t state;
	float lastx;
	float lasty;
};