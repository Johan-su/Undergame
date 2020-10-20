#pragma once
#include <SDL.h>
#include "DebugMacros.h"
#include "ECS.h"
struct InputComponent
{
	bool buttonStates[7];
	float x;
	float y;

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};